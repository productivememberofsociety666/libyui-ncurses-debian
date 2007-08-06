/*---------------------------------------------------------------------\
|                                                                      |
|                      __   __    ____ _____ ____                      |
|                      \ \ / /_ _/ ___|_   _|___ \                     |
|                       \ V / _` \___ \ | |   __) |                    |
|                        | | (_| |___) || |  / __/                     |
|                        |_|\__,_|____/ |_| |_____|                    |
|                                                                      |
|                               core system                            |
|                                                        (C) SuSE GmbH |
\----------------------------------------------------------------------/

   File:       NCPopupInfo.cc

   Author:     Gabriele Strattner <gs@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#include "Y2Log.h"
#include "NCPopupInfo.h"

#include "NCTree.h"
#include "YMenuButton.h"
#include "YDialog.h"
#include "NCSplit.h"
#include "NCSpacing.h"

namespace
{
    const YCPTerm idOk( "ok" );
    const YCPTerm idCancel( "cancel" );
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupInfo::NCPopupInfo
//	METHOD TYPE : Constructor
//
//	DESCRIPTION :
//
NCPopupInfo::NCPopupInfo( const wpos at,
			  const YCPString & headline,
			  const YCPString & text,
			  string okButtonLabel,
			  string cancelButtonLabel,
			  string printLicenseText )
    : NCPopup( at, false )
      , helpText( 0 )
      , okButton( 0 )
      , cancelButton( 0 )
      , hDim( 50 )
      , vDim( 20 )
      , visible ( false )
{
    createLayout( headline, text, okButtonLabel, cancelButtonLabel, printLicenseText );
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupInfo::~NCPopupInfo
//	METHOD TYPE : Destructor
//
//	DESCRIPTION :
//
NCPopupInfo::~NCPopupInfo()
{
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupInfo::createLayout
//	METHOD TYPE : void
//
//	DESCRIPTION :
//
void NCPopupInfo::createLayout( const YCPString & headline,
				const YCPString & text,
				string okButtonLabel,
				string cancelButtonLabel,
			        string printLicenseText )
{

  YWidgetOpt opt;

  // the vertical split is the (only) child of the dialog
  NCSplit * split = new NCSplit( this, opt, YD_VERT );
  addChild( split );
  
  // add the headline
  opt.isHeading.setValue( true );
  NCLabel * head = new NCLabel( split, opt, headline );
  split->addChild( head );
  
  // add the rich text widget 
  helpText = new NCRichText( split, opt, text );
  split->addChild( helpText );

  if (printLicenseText != "" ) 
  { 
      NCLabel *printLabel = new NCLabel (split, opt, printLicenseText );
      split->addChild( new NCSpacing( split, opt, 1, false, true ) ); 
      split->addChild( printLabel );
      split->addChild( new NCSpacing( split, opt, 1, false, true ) ); 
  }  

  NCSplit * hSplit = new NCSplit( split, opt, YD_HORIZ );
  split->addChild( hSplit );
  if ( okButtonLabel != "" && cancelButtonLabel != "" )
  {
      opt.isHStretchable.setValue( true );
      hSplit->addChild( new NCSpacing( hSplit, opt, 0.4, true, false ) ); 
  }

  if ( okButtonLabel != "" )
  {
      opt.key_Fxx.setValue( 10 );
      // add the OK button
      okButton = new NCPushButton( hSplit, opt, YCPString(okButtonLabel) );
      okButton->setId( YCPString(idOk->name()) );
  
      hSplit->addChild( okButton );
  }
  
  if ( cancelButtonLabel != "" )
  {
      hSplit->addChild( new NCSpacing( hSplit, opt, 0.4, true, false ) );
      
      opt.key_Fxx.setValue( 9 );
      // add the Cancel button
      cancelButton = new NCPushButton( hSplit, opt, YCPString(cancelButtonLabel) );
      cancelButton->setId( YCPString(idCancel->name()) );
      hSplit->addChild( cancelButton );
      
      hSplit->addChild( new NCSpacing( hSplit, opt, 0.4, true, false ) ); 
  }
  split->addChild( new NCSpacing( split, opt, 0.5, false, true ) ); 
  
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupInfo::showInfoPopup
//	METHOD TYPE : NCursesEvent &
//
//	DESCRIPTION :
//
NCursesEvent & NCPopupInfo::showInfoPopup( )
{
    postevent = NCursesEvent();
    do {
	popupDialog( );
    } while ( postAgain() );
    
    popdownDialog();

    return postevent;
}

void NCPopupInfo::popup()
{
    	initDialog();
	showDialog();
	activate ( true );
	visible = true;
}

void NCPopupInfo::popdown()
{
    	activate ( false );
	closeDialog();
	visible = false;
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupInfo::niceSize
//	METHOD TYPE : void
//
//	DESCRIPTION :
//

long NCPopupInfo::nicesize(YUIDimension dim)
{
    long vertDim = vDim;
    long horDim = hDim;
    
    if ( vDim >= NCurses::lines() )
	vertDim = NCurses::lines()-5;
    if ( hDim >= NCurses::cols() )
	horDim = NCurses::cols()-10;
    return ( dim == YD_HORIZ ? horDim : vertDim );
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopup::wHandleInput
//	METHOD TYPE : NCursesEvent
//
//	DESCRIPTION :
//
NCursesEvent NCPopupInfo::wHandleInput( wint_t ch )
{
    if ( ch == 27 ) // ESC
	return NCursesEvent::cancel;

    if ( ch == KEY_RETURN )
	return NCursesEvent::button;

    return NCDialog::wHandleInput( ch );
}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupInfo::postAgain
//	METHOD TYPE : bool
//
//	DESCRIPTION :
//
bool NCPopupInfo::postAgain()
{
    if ( ! postevent.widget )
	return false;

    if ( okButton && cancelButton )
    {
	YCPValue currentId =  dynamic_cast<YWidget *>(postevent.widget)->id();

	if ( !currentId.isNull()
	     && currentId->compare( YCPString(idCancel->name()) ) == YO_EQUAL )
	{
	    // close the dialog 
	    postevent = NCursesEvent::cancel;
	}
	// else - nothing to do (postevent is already set)
    }
    
    if ( postevent == NCursesEvent::button || postevent == NCursesEvent::cancel )
    {
        // return false means: close the popup dialog
	return false;
    }
    return true;
}


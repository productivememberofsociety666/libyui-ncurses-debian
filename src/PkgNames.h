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

   File:       PkgNames.h

   Author:     Gabriele Strattner <gs@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#ifndef PkgNames_h
#define PkgNames_h

#include "NCstring.h"
#include <string>


// Forward declaration
class YCPValue;


// Class to make available globally used names in package selection dialog,
// such as widget ids, text which has to be translated and so on

class PkgNames
{
public:
    
    /**
     *  Widget id of the package table ( list of packages )
     */
    static const YCPValue& Packages ();

    /**
     *  Widget id of the list of available packages
     */
    static const YCPValue& AvailPkgs ();

    /**
     *  Widget id of the list of patch packages
     */
    static const YCPValue& PatchPkgs ();

    /**
     *	Widget id of the description section ( shown on bottom of the selection dialog )
     */
    static const YCPValue& Description ();

    /**
     *  Widget id of the file list information ( shown on bottom of the selection dialog )
     */
    static const YCPValue& FilelistId ();

    /**
     * Widget id of the ReplacePoint
     */
    static const YCPValue& ReplPoint();
    
    /**
     * Widget id of the menu selection Action/Toggle
     */
    static const YCPValue& Toggle ();

    /**
     * Widget id of the menu selection Action/Select
     */
    static const YCPValue& Select ();

    /**
     * Widget id of the menu selection Action/All packages/Select all
     */
    static const YCPValue& SelectAll ();

    /**
     * Widget id of the menu selection Action/Delete
     */
    static const YCPValue& Delete ();

    /**
     * Widget id of the menu selection Action/Taboo On
     */
    static const YCPValue& TabooOn ();

   /**
     * Widget id of the menu selection Action/Taboo Off 
     */
    static const YCPValue& TabooOff ();
    
   /**
     * Widget id of the menu selection Action/SPM yes/no
     */
    static const YCPValue& ToggleSource ();
    
    /**
     * Widget id of the menu selection Action/All packages/Delete all
     */
    static const YCPValue& DeleteAll ();

    /**
     * Widget id of the menu selection Action/All packages/Update all
     */
    static const YCPValue& UpdateAll();
    /**
     * Widget id of the menu selection Action/Update
     */
    static const YCPValue& Update ();
    
    /**
     *  Widget id of the search button
     */
    static const YCPValue& Search ();

    /**
     *  Widget id of the menu selection Information/Long description
     */
    static const YCPValue& LongDescr ();

    /**
     *  Widget id of the menu selection Information/Versions
     */
    static const YCPValue& Versions ();
    
    /**
     *  Widget id of the menu selection Information/Package info
     */
    static const YCPValue& PkgInfo ();

    /**
     *  Widget id of the menu selection Information/File list
     */
    static const YCPValue& Files ();

   /**
     *  Widget id of the menu selection Help/Udpate
     */
    static const YCPValue& PkgNames::UpdateHelp ();  

    /**
     *  Widget id of the menu selection Help/Search
     */
    static const YCPValue& PkgNames::SearchHelp ();
    
    /**
     *  Widget id of the menu selection Information/Relaione
     */
    static const YCPValue& PkgNames::Relations ();
    
    /**
     *  Widget id of the menu selection RPM groups
     */
    static const YCPValue& RpmGroups ();

    /**
     *  Widget id of the menu selection Selections
     */
    static const YCPValue& Selections ();

    /**
     *  Widget id of the menu selection update list
     */
    static const YCPValue& UpdateList ();

    /**
     *  Widget id of the label which shows the selected filter
     */
    static const YCPValue& Filter ();

    /**
     *  Widget id of the label for disk space information
     */
    static const YCPValue& Diskspace ();

    static const YCPValue& ShowDeps ();
    static const YCPValue& AutoDeps ();
    static const YCPValue& ReplaceMenu ();

    /**
     *  Widget id of the button disk space
     */
    static const YCPValue& Diskinfo ();

    /**
     *  Widget id of the cancel button
     */
    static const YCPValue& Cancel ();

    /**
     *  Widget id of the ok button
     */
    static const YCPValue& OkButton ();

    /**
     *  Widget id combo box
     */
    static const YCPValue& SearchBox ();
    
   /**
     *  Widget id of the solve button
     */
    static const YCPValue& Solve ();
    
    /**
     *  Widget id of general help menu item
     */
    static const YCPValue& GeneralHelp ();
    
   /**
     *  Widget id of status help menu item
     */
    static const YCPValue& StatusHelp ();

    /**
     *  Widget id of filter help menu item
     */
    static const YCPValue& FilterHelp ();

    /**
     *  Widget id of  help  YOU
     */
    static const YCPValue& PatchHelp ();
    
    /**
     *  Widget id of Filter/recommended
     */
    static const YCPValue& Recommended ();

   /**
     *  Widget id of Filter/security
     */
    static const YCPValue& Security ();

    /**
     *  Widget id of Filter/installed
     */
    static const YCPValue& InstalledPatches ();

    /**
     *  Widget id of Filter/all patches
     */
    static const YCPValue& AllPatches ();

   /**
     *  Widget id information patch descr
     */
    static const YCPValue& PatchDescr ();

    /**
     *  Widget id information patch packages
     */
    static const YCPValue& PatchPackages ();

    /**
     *  Internal use (id for the tree items)
     */
    static const YCPValue& Treeitem();

    /**
     *  The label of the RPM-group-tags tree widget
     */
    static const NCstring RpmTreeLabel();

    /**
     *  The headline of the disk space popup
     */ 
    static const NCstring PkgNames::DiskspaceLabel();

   /**
     *  The label of the package selections popup
     */
    static const NCstring SelectionLabel();

   /**
     *  The label Filter: YOU Patches
     */
    static const NCstring YOUPatches();
    
    /**
     *  The label for Filter: Search results
     */
    static const NCstring SearchResults();

    /**
     *  The label for Filter: Update problem
     */
    static const NCstring UpdateProblem();
    
    /**
     * The headline of the search popup
     */
    static const NCstring PackageSearch();

    /**
     * The headline of the dependency popup
     */
    static const NCstring PackageDeps();

    static const NCstring LabelUnres1();
    static const NCstring LabelUnres2();
    static const NCstring LabelAlternative();
    static const NCstring LabelConflict1();
    static const NCstring LabelConflict2();
    static const NCstring LabelRequBy1();
    static const NCstring LabelRequBy2();
    static const NCstring LabelRequire1();
    static const NCstring LabelRequire2();
    static const NCstring LabelUnresolvable();
    static const NCstring WarningLabel();
    static const NCstring ErrorLabel();
    static const NCstring NotifyLabel();
    static const NCstring DepsHelpLine();
    static const NCstring Solving();
    static const NCstring ContinueRequ();
    
   /**
     * text used in search popup
     */
    static const NCstring SearchPhrase();

   /**
     * text used in search popup
     */
    static const NCstring CheckDescr();
    
   /**
     * text used in search popup
     */
    static const NCstring IgnoreCase();

   /**
     * text used in search popup
     */
    static const NCstring SearchIn();

   /**
     * text used in search popup
     */
    static const NCstring CheckName();
    
   /**
     * text used in search popup
     */
    static const NCstring CheckSummary();

       /**
     * text used in search popup
     */
    static const NCstring CheckProvides();
    
   /**
     * text used in search popup
     */
    static const NCstring CheckRequires();
    
    /**
     * The headline of the help popup
     */
    static const NCstring PackageHelp();

    /**
     * The headline of the search help popup
     */
    static const NCstring SearchHeadline();
    
    /**
     * The headline of the help YOU popup
     */
    static const NCstring YouHelp();

    /**
     *  The label of the OK button
     */
    static const NCstring OKLabel();

    /**
     *  The label of the Cancel button
     */
    static const NCstring CancelLabel();
    
    /**
     *  The label of the Cancel/Ignore button
     */
    static const NCstring CancelIgnore();
    
    /**
     *  The label of the Solve button
     */
    static const NCstring SolveLabel();
    
    /**
     * The label of the file list frame
     */
    static const NCstring FileList();
    
    /**
     * Part 1 of help text package installation
     */
    static const NCstring HelpPkgInst1();

    /**
     * Part 12 of help text package installation
     */
    static const NCstring HelpPkgInst12();

    /**
     * Part 13 of help text package installation
     */
    static const NCstring HelpPkgInst13();

    /**
     * help text package status
     */
    static const NCstring HelpOnStatus1();
    static const NCstring HelpOnStatus2();
    static const NCstring HelpOnStatus3(); 
    static const NCstring HelpOnStatus();

    static const NCstring YouHelp1();
    static const NCstring YouHelp2();
    static const NCstring YouHelp3();
   /**
     * Part of help text used in installed system
     */
    static const NCstring HelpPkgPostInst();

    /**
     * Part 2 of help text package installation
     */
    static const NCstring HelpPkgInst2();
       /**
     * Part 3 of help text package installation
     */
    static const NCstring HelpPkgInst3();
    /**
     * Part 4 of help text package installation
     */
    static const NCstring HelpPkgInst4();

    /**
     * Part 5 of help text package installation
     */
    static const NCstring HelpPkgInst5();

    static const NCstring HelpOnUpdate();

    /**
     * help package search
     */
    static const NCstring HelpOnSearch();

    /**
     * bold text Version: (richtext) 
     */
    static const NCstring Version();

    /**
     * bold text Installed version: (richtext) 
     */
    static const NCstring InstVersion();

    /**
     * bold text License: (richtext) 
     */
    static const NCstring License();

    /**
     * bold text Media No.: (richtext) 
     */
    static const NCstring MediaNo();
    
    /**
     * bold text Size: (richtext) 
     */
    static const NCstring Size();

    /**
     * bold text Authors: (richtext) 
     */
    static const NCstring Authors();

    /**
     * bold text Provides: (richtext) 
     */
    static const NCstring Provides();

    /**
     * bold text Description: (richtext) 
     */
    static const NCstring ShortDescr();
    
    /**
     * bold text Requires: (richtext) 
     */
    static const NCstring Requires();

    /**
     * bold text Required by: (richtext) 
     */
    static const NCstring PreRequires();

    /**
     * bold text Conflicts with: (richtext) 
     */
    static const NCstring Conflicts();
    
    /**
     *  Column header package name
     */
    static const NCstring PkgName();

     /**
     *  Column header package version installed
     */
    static const NCstring PkgVersion();

    /**
     *  Column header package version new
     */
    static const NCstring PkgVersionNew();

    /**
     *  Column header package version installed
     */
    static const NCstring PkgVersionInst();
    
    /**
     *  Column header package summary
     */
    static const NCstring PkgSummary();

    /**
     *  Column header package size
     */
    static const NCstring PkgSize();

     /**
     *  Column header patch kind
     */
    static const NCstring PatchKind();
    
    /**
     *  Column header package status
     */
    static const NCstring PkgStatus();

    /**
     * dependency popup text
     */ 
    static const NCstring RequText();
    static const NCstring RequByText();
    static const NCstring UnresText();
    static const NCstring NoAvailText();
    static const NCstring NeedsText();
    static const NCstring ConflictText();
    static const NCstring NoConflictText();

    static const NCstring MenuEtc();
    static const NCstring MenuDeps();
    static const NCstring MenuCheckDeps();
    static const NCstring MenuAutoDeps();
    static const NCstring MenuNoAutoDeps();
    static const NCstring MenuSel();
    static const NCstring MenuSaveSel();	
    static const NCstring MenuLoadSel();
    
private:
    
    // Need no object of this class: hide default constructor
    PkgNames();

    /**
     *  Create an id value with ` at the beginning
     */
    static YCPValue createIdValue ( const std::string &name );

    /**
     *  Convert a NCstring into a YCPString
     */
    static YCPString toYCPString ( const NCstring & str );

};


///////////////////////////////////////////////////////////////////

#endif // PkgNames_h




// READABILITY (auto CF):
//  - Body size: ~268 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00950a40×263, FUN_00959230.
//  - Strings: "activateallcreatures"; "assetreport"; "assist"; "adddisciplinepoints".
//  - Return sites: 1.

// =============================================================================
// Mission_debugcompleteobjective
// -----------------------------------------------------------------------------
// Stable ID: aa_00959230
// Address:   0x00959230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "debugcompleteobjective"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_debugcompleteobjective(void)



{

  int unaff_ESI;

  

  FUN_00950a40(unaff_ESI,&DAT_00a2bdf4,1);

  FUN_00950a40(unaff_ESI,"activateallcreatures",1);

  FUN_00950a40(unaff_ESI,"assetreport",0);

  FUN_00950a40(unaff_ESI,"assist",0);

  FUN_00950a40(unaff_ESI,"adddisciplinepoints",1);

  FUN_00950a40(unaff_ESI,"addresearchpoints",1);

  FUN_00950a40(unaff_ESI,"addhazardcount",1);

  FUN_00950a40(unaff_ESI,"addcredits",1);

  FUN_00950a40(unaff_ESI,"buildassetcatalog",1);

  FUN_00950a40(unaff_ESI,"bullettime",1);

  FUN_00950a40(unaff_ESI,"bullettimestep",1);

  FUN_00950a40(unaff_ESI,"broadcast",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2baf0,0);

  FUN_00950a40(unaff_ESI,"bugtest",5);

  FUN_00950a40(unaff_ESI,"cbidsearch",1);

  FUN_00950a40(unaff_ESI,"changeinstance",1);

  FUN_00950a40(unaff_ESI,"checkitems",1);

  FUN_00950a40(unaff_ESI,&DAT_00a2b9c4,0);

  FUN_00950a40(unaff_ESI,"claninvite",0);

  FUN_00950a40(unaff_ESI,"clankick",0);

  FUN_00950a40(unaff_ESI,"createitem",1);

  FUN_00950a40(unaff_ESI,"createasset",1);

  FUN_00950a40(unaff_ESI,"convoy",0);

  FUN_00950a40(unaff_ESI,"camera",1);

  FUN_00950a40(unaff_ESI,"chattest",1);

  FUN_00950a40(unaff_ESI,"castskill",1);

  FUN_00950a40(unaff_ESI,"damage",1);

  FUN_00950a40(unaff_ESI,"debugstats",0);

  FUN_00950a40(unaff_ESI,"debugvars",1);

  FUN_00950a40(unaff_ESI,"debugvaroutput",1);

  FUN_00950a40(unaff_ESI,"debugodometer",1);

  FUN_00950a40(unaff_ESI,"debugtriggers",1);

  FUN_00950a40(unaff_ESI,"debugtriggeract",1);

  FUN_00950a40(unaff_ESI,"debugmissions",1);

  FUN_00950a40(unaff_ESI,"debugcompleteobjective",1);

  FUN_00950a40(unaff_ESI,"debugmissionstring",1);

  FUN_00950a40(unaff_ESI,"debugundomissions",1);

  FUN_00950a40(unaff_ESI,"debugunlock",1);

  FUN_00950a40(unaff_ESI,"debugsetgate",1);

  FUN_00950a40(unaff_ESI,"debugforcemission",1);

  FUN_00950a40(unaff_ESI,"debugprintglom",1);

  FUN_00950a40(unaff_ESI,"debugcompletepocket",1);

  FUN_00950a40(unaff_ESI,"demote",0);

  FUN_00950a40(unaff_ESI,"disband",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2b424,*(uint8_t *)(unaff_ESI + 0x9cd));

  FUN_00950a40(unaff_ESI,"effect",1);

  FUN_00950a40(unaff_ESI,"enterarena",1);

  FUN_00950a40(unaff_ESI,"enemy",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2b350,0);

  FUN_00950a40(unaff_ESI,"flushglom",1);

  FUN_00950a40(unaff_ESI,"flushrender",1);

  FUN_00950a40(unaff_ESI,"flushlockedrender",1);

  FUN_00950a40(unaff_ESI,"forceflipper",1);

  FUN_00950a40(unaff_ESI,"findobject",1);

  FUN_00950a40(unaff_ESI,"friend",0);

  FUN_00950a40(unaff_ESI,"global",1);

  FUN_00950a40(unaff_ESI,"giveexp",1);

  FUN_00950a40(unaff_ESI,"gototrigger",1);

  FUN_00950a40(unaff_ESI,"gotoplayer",1);

  FUN_00950a40(unaff_ESI,"givemedal",1);

  FUN_00950a40(unaff_ESI,"gmhelp",1);

  FUN_00950a40(unaff_ESI,&DAT_00a2b18c,0);

  FUN_00950a40(unaff_ESI,"hotkeys",1);

  FUN_00950a40(unaff_ESI,"ignore",0);

  FUN_00950a40(unaff_ESI,"incompletemissions",1);

  FUN_00950a40(unaff_ESI,"invite",0);

  FUN_00950a40(unaff_ESI,"initjoystick",0);

  FUN_00950a40(unaff_ESI,"interfaceedit",1);

  FUN_00950a40(unaff_ESI,"listattrs",1);

  FUN_00950a40(unaff_ESI,"levelup",1);

  FUN_00950a40(unaff_ESI,"leavearena",0);

  FUN_00950a40(unaff_ESI,"leavechat",0);

  FUN_00950a40(unaff_ESI,"leave",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2af28,0);

  FUN_00950a40(unaff_ESI,"listtags",1);

  FUN_00950a40(unaff_ESI,"loadallobjects",1);

  FUN_00950a40(unaff_ESI,"loadasset",1);

  FUN_00950a40(unaff_ESI,&DAT_00a2ae64,0);

  FUN_00950a40(unaff_ESI,"local",0);

  FUN_00950a40(unaff_ESI,"mapsearch",1);

  FUN_00950a40(unaff_ESI,"massmove",1);

  FUN_00950a40(unaff_ESI,"mouse",1);

  FUN_00950a40(unaff_ESI,"memorize",1);

  FUN_00950a40(unaff_ESI,"music",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2ad34,1);

  FUN_00950a40(unaff_ESI,"nodeath",1);

  FUN_00950a40(unaff_ESI,&DAT_00a2ad10,1);

  FUN_00950a40(unaff_ESI,"opendlg",1);

  FUN_00950a40(unaff_ESI,"options",1);

  FUN_00950a40(unaff_ESI,&DAT_00a2ac60,1);

  FUN_00950a40(unaff_ESI,"playmusic",1);

  FUN_00950a40(unaff_ESI,"playchannel",1);

  FUN_00950a40(unaff_ESI,"printassets",1);

  FUN_00950a40(unaff_ESI,"promote",0);

  FUN_00950a40(unaff_ESI,"popup",1);

  FUN_00950a40(unaff_ESI,"power",1);

  FUN_00950a40(unaff_ESI,"pumpkinhavok",1);

  FUN_00950a40(unaff_ESI,"pumpkinclient",1);

  FUN_00950a40(unaff_ESI,"quickbar",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2ab00,*(uint8_t *)(unaff_ESI + 0x9cd));

  FUN_00950a40(unaff_ESI,"randomcar",1);

  FUN_00950a40(unaff_ESI,"randomizecargoandlocker",1);

  FUN_00950a40(unaff_ESI,"randomizecargo",1);

  FUN_00950a40(unaff_ESI,"randy",1);

  FUN_00950a40(unaff_ESI,"reloadfx",1);

  FUN_00950a40(unaff_ESI,"reloadcbid",1);

  FUN_00950a40(unaff_ESI,"reloaddistortion",1);

  FUN_00950a40(unaff_ESI,"reloadfluid",1);

  FUN_00950a40(unaff_ESI,"reloadparticlefx",1);

  FUN_00950a40(unaff_ESI,"reloadphysicsdisplay",1);

  FUN_00950a40(unaff_ESI,"recalculateallskirts",1);

  FUN_00950a40(unaff_ESI,"reloadai",1);

  FUN_00950a40(unaff_ESI,"reloadlanguage",1);

  FUN_00950a40(unaff_ESI,"rejointournament",1);

  FUN_00950a40(unaff_ESI,"resetsound",1);

  FUN_00950a40(unaff_ESI,"revealmap",1);

  FUN_00950a40(unaff_ESI,"reverse",1);

  FUN_00950a40(unaff_ESI,&DAT_00a2a7d8,0);

  FUN_00950a40(unaff_ESI,"sector",0);

  FUN_00950a40(unaff_ESI,&DAT_00a2a79c,0);

  FUN_00950a40(unaff_ESI,"setvolume",0);

  FUN_00950a40(unaff_ESI,"seteffectcomplexity",1);

  FUN_00950a40(unaff_ESI,"setenv",1);

  FUN_00950a40(unaff_ESI,"setfov",0);

  FUN_00950a40(unaff_ESI,"setframelimit",1);

  FUN_00950a40(unaff_ESI,"setmaxmipsize",0);

  FUN_00950a40(unaff_ESI,"setgamma",0);

  FUN_00950a40(unaff_ESI,"setpolyphony",1);

  FUN_00950a40(unaff_ESI,"setmaxsounds",1);

  FUN_00950a40(unaff_ESI,"setdistance",1);

  FUN_00950a40(unaff_ESI,"setcredits",1);

  FUN_00950a40(unaff_ESI,"setspeedfov",1);

  FUN_00950a40(unaff_ESI,"setrolloff",1);

  FUN_00950a40(unaff_ESI,"setcamera",9);

  FUN_00950a40(unaff_ESI,"settrim",1);

  FUN_00950a40(unaff_ESI,"setplayerdamageglobal",1);

  FUN_00950a40(unaff_ESI,"setcreaturedamageglobal",1);

  FUN_00950a40(unaff_ESI,"setplayerskilldamageglobal",1);

  FUN_00950a40(unaff_ESI,"setcreatureskilldamageglobal",1);

  FUN_00950a40(unaff_ESI,"settrick",1);

  FUN_00950a40(unaff_ESI,"setprimary",1);

  FUN_00950a40(unaff_ESI,"setsecondary",1);

  FUN_00950a40(unaff_ESI,"settimer",1);

  FUN_00950a40(unaff_ESI,"setnetwork",1);

  FUN_00950a40(unaff_ESI,"setnearplane",1);

  FUN_00950a40(unaff_ESI,"setfadenearfar",9);

  FUN_00950a40(unaff_ESI,"settreecull",1);

  FUN_00950a40(unaff_ESI,"setcullingdistance",1);

  FUN_00950a40(unaff_ESI,"setcullingscalar",1);

  FUN_00950a40(unaff_ESI,"setgrasscull",0);

  FUN_00950a40(unaff_ESI,"setgrassfade",0);

  FUN_00950a40(unaff_ESI,"setgravity",1);

  FUN_00950a40(unaff_ESI,"setlodbias",0);

  FUN_00950a40(unaff_ESI,"setlodscalar",0);

  FUN_00950a40(unaff_ESI,"setteamfaction",1);

  FUN_00950a40(unaff_ESI,&DAT_00a29ffc,0);

  FUN_00950a40(unaff_ESI,"shadowtoggle",0);

  FUN_00950a40(unaff_ESI,"shadowmaptoggle",1);

  FUN_00950a40(unaff_ESI,"shout",0);

  FUN_00950a40(unaff_ESI,"showinstances",1);

  FUN_00950a40(unaff_ESI,"showmsg",1);

  FUN_00950a40(unaff_ESI,"shownetwork",1);

  FUN_00950a40(unaff_ESI,"showwarning",1);

  FUN_00950a40(unaff_ESI,"showpal",1);

  FUN_00950a40(unaff_ESI,"showenvsettings",1);

  FUN_00950a40(unaff_ESI,"showsoundregions",1);

  FUN_00950a40(unaff_ESI,"showtricks",1);

  FUN_00950a40(unaff_ESI,"skillmode",1);

  FUN_00950a40(unaff_ESI,"sound",0);

  FUN_00950a40(unaff_ESI,"soundtest",1);

  FUN_00950a40(unaff_ESI,"stopmusic",1);

  FUN_00950a40(unaff_ESI,"stuck",0);

  FUN_00950a40(unaff_ESI,"suggest",0);

  FUN_00950a40(unaff_ESI,"summon",1);

  FUN_00950a40(unaff_ESI,"switchstats",0);

  FUN_00950a40(unaff_ESI,"testmap",1);

  FUN_00950a40(unaff_ESI,"testroll",1);

  FUN_00950a40(unaff_ESI,&DAT_00a29bfc,0);

  FUN_00950a40(unaff_ESI,"testmissionadd",1);

  FUN_00950a40(unaff_ESI,"testservershutdown",1);

  FUN_00950a40(unaff_ESI,"teleport",1);

  FUN_00950a40(unaff_ESI,&DAT_00a29b04,0);

  FUN_00950a40(unaff_ESI,"toggleweather",1);

  FUN_00950a40(unaff_ESI,"togglefog",0);

  FUN_00950a40(unaff_ESI,"toggleoverdraw",0);

  FUN_00950a40(unaff_ESI,"toggleoldshadows",0);

  FUN_00950a40(unaff_ESI,"togglereflect",0);

  FUN_00950a40(unaff_ESI,"toggleglomming",1);

  FUN_00950a40(unaff_ESI,"toggledeathscreen",1);

  FUN_00950a40(unaff_ESI,"toggledebugstats",0);

  FUN_00950a40(unaff_ESI,"toggledebugtokens",9);

  FUN_00950a40(unaff_ESI,"toggledrawmost",0);

  FUN_00950a40(unaff_ESI,"toggledrawtriggers",1);

  FUN_00950a40(unaff_ESI,"toggledrawspawns",1);

  FUN_00950a40(unaff_ESI,"toggledrawall",0);

  FUN_00950a40(unaff_ESI,"toggledrawgloms",0);

  FUN_00950a40(unaff_ESI,"toggledrawfake",0);

  FUN_00950a40(unaff_ESI,"toggledrawroads",0);

  FUN_00950a40(unaff_ESI,"toggledrawnophysics",0);

  FUN_00950a40(unaff_ESI,"toggledrawphysics",0);

  FUN_00950a40(unaff_ESI,"toggledrawvehicle",0);

  FUN_00950a40(unaff_ESI,"togglemegaglom",1);

  FUN_00950a40(unaff_ESI,"toggledrawactive",0);

  FUN_00950a40(unaff_ESI,"toggledrawstatic",0);

  FUN_00950a40(unaff_ESI,"toggledrawterrain",0);

  FUN_00950a40(unaff_ESI,"toggledrawskybox",0);

  FUN_00950a40(unaff_ESI,"toggledrawparticles",0);

  FUN_00950a40(unaff_ESI,"togglepickall",1);

  FUN_00950a40(unaff_ESI,"togglestepparticles",0);

  FUN_00950a40(unaff_ESI,"toggleled",1);

  FUN_00950a40(unaff_ESI,"togglelocalvdb",1);

  FUN_00950a40(unaff_ESI,"toggleplayerai",1);

  FUN_00950a40(unaff_ESI,"togglewireframe",0);

  FUN_00950a40(unaff_ESI,"togglespectator",1);

  FUN_00950a40(unaff_ESI,"togglefilterblur",1);

  FUN_00950a40(unaff_ESI,"togglefilterbright",1);

  FUN_00950a40(unaff_ESI,"togglefilterspec",0);

  FUN_00950a40(unaff_ESI,"toggledrive",1);

  FUN_00950a40(unaff_ESI,"toggleshadow",0);

  FUN_00950a40(unaff_ESI,"toggledrawdistortion",1);

  FUN_00950a40(unaff_ESI,"toggletreelod",0);

  FUN_00950a40(unaff_ESI,"toggledrawrefraction",0);

  FUN_00950a40(unaff_ESI,"toggleupdatemap",1);

  FUN_00950a40(unaff_ESI,"tournamentstart",1);

  FUN_00950a40(unaff_ESI,"trade",0);

  FUN_00950a40(unaff_ESI,"transfertest",1);

  FUN_00950a40(unaff_ESI,"toggledrawnewterrain",0);

  FUN_00950a40(unaff_ESI,"togglespiraldraw",9);

  FUN_00950a40(unaff_ESI,"togglefading",9);

  FUN_00950a40(unaff_ESI,"setloadqueue",9);

  FUN_00950a40(unaff_ESI,"validateobjlist",1);

  FUN_00950a40(unaff_ESI,"whisper",0);

  FUN_00950a40(unaff_ESI,&DAT_00a294a4,0);

  FUN_00950a40(unaff_ESI,"waypoint",1);

  FUN_00950a40(unaff_ESI,&DAT_00a29440,0);

  FUN_00950a40(unaff_ESI,"spawncbid",1);

  FUN_00950a40(unaff_ESI,"perfmon",1);

  FUN_00950a40(unaff_ESI,"serverstats",1);

  FUN_00950a40(unaff_ESI,"togglevdb",1);

  FUN_00950a40(unaff_ESI,&DAT_00a292d8,1);

  FUN_00950a40(unaff_ESI,&DAT_00a292b4,3);

  FUN_00950a40(unaff_ESI,&DAT_00a29280,3);

  FUN_00950a40(unaff_ESI,"unban",3);

  FUN_00950a40(unaff_ESI,&DAT_00a291f0,1);

  FUN_00950a40(unaff_ESI,"gmwho",1);

  FUN_00950a40(unaff_ESI,"characterdebug",1);

  FUN_00950a40(unaff_ESI,"spamlogger",9);

  FUN_00950a40(unaff_ESI,"untargetable",1);

  FUN_00950a40(unaff_ESI,"invisible",1);

  FUN_00950a40(unaff_ESI,"playerrename",0);

  FUN_00950a40(unaff_ESI,"carrename",3);

  FUN_00950a40(unaff_ESI,"freeze",3);

  FUN_00950a40(unaff_ESI,"unfreeze",3);

  FUN_00950a40(unaff_ESI,"copychat",1);

  FUN_00950a40(unaff_ESI,&DAT_00a28fc0,1);

  FUN_00950a40(unaff_ESI,&DAT_00a28f94,1);

  FUN_00950a40(unaff_ESI,"guildleaderwho",1);

  FUN_00950a40(unaff_ESI,"guildrename",3);

  FUN_00950a40(unaff_ESI,"guildtransferowner",3);

  FUN_00950a40(unaff_ESI,"chatban",3);

  FUN_00950a40(unaff_ESI,"unchatban",3);

  FUN_00950a40(unaff_ESI,"reclaim",1);

  FUN_00950a40(unaff_ESI,&DAT_00a28db8,3);

  return;

}

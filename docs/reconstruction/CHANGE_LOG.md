# Change Log

## 2026-08-06 - B1000 dual burst LAUNCHED (goal-mandated 1000 agents)

- Partition: `reviews/WAVE_2026-08-06_b1000_burst_partition_map.md` — **1000 unique** OWN VAs.
- Workflow: `.grok/workflows/b1000-dual-burst.rhai` — self-contained panel, `agent_budget=1000`.
- Launch: **1000** agents attempted (display handle `b1000-dual-burst`). Dual start **2726**.
- Policy: verification-oriented OWN duals; dual/`full`/`reviewed` remain **byproducts**, not completion.
- Parent merge deferred until filesystem A∩B recount; OWN agents do not edit parent ledgers.

## 2026-08-06 - Verification-first policy (coverage not completion)

- **Policy:** Never optimize for coverage metrics. Coverage is a byproduct.
  A function is complete only under project verification requirements.
  Scaffolds / placeholders / partial docs must **not** increase any completion metric.
- Dual / `full` / `reviewed` remain **depth and accounting byproducts**, not goals.

## 2026-08-05 - R13 residual dual wave sealed + WQ-AUDIT-002 dual/reviewed reconcile

- R13 partition 40/40 dual A/B sealed (filesystem). Dual unique **2686 → 2726** (+40 R13).
- Inventory R13 OWN set promoted full→reviewed; then **WQ-AUDIT-002 bulk**: every dualed VA with status `full` → `reviewed` (**+2565**).
- Inventory after reconcile: full **14437** · trivial-batch **8508** · reviewed **2726** (= dual A∩B).
- `progress.json` dual_ab_pairs=2726 matches filesystem; tests `test_inventory_terminal_accounting` OK.
- **CAP-004 / WQ-AUDIT-003:** residual STL dual volume waves remain **frozen** — **no R14**.
- Next: audit P0 banners + user-facing WQ verticals (not more FUN_*/STL leaf dual waves).

## 2026-08-05 - AUDIT-2026-08-05-01 independent process audit (PARTIAL FAILURE)

- Full audit under `docs/reconstruction/audits/` (`CURRENT_AUDIT`, `AUDIT_FINDINGS`, `SAMPLED_ITEMS`, `SYSTEMIC_RISKS`, `CORRECTIVE_ACTION_PLAN`).
- Rating: **PARTIAL FAILURE** — industrial `full`/terminal accounting overstates depth (~81% Partial scaffold); dual ~2724 vs inventory reviewed 121; residual STL dual volume frozen; HP dual samples largely hold under live Ghidra bytes/decomp.
- Dual recount: filesystem A∩B **2724** (progress.json refreshed); residual dual waves **frozen** (CAP-004).
- Work queue: WQ-AUDIT-001..006 added; R13 volume expansion not continued.
- Isolated fixes: InventoryGrab clean header comment (refresh vtbl+4 vs GetObject +0x3ac); **HasCompletedMission mode-gate `this` = attach object** (F-027, CAP-019 partial).
- Adversarial subagent: drive setters Confirmed body; InventoryGrab/Equip pack CF hold; CompleteObjective conf. inflation; FUN_0048dde0 scaffold-only.
- Tests at audit: dual match fixed after recount; undefined4 policy still open CAP-011.

## 2026-08-05 - R13 residual dual wave (landed under audit freeze)

- Partition: `reviews/WAVE_2026-08-05_r13_residual_partition_map.md` (40 OWN agents R13-001…040).
- Dual start **2686**; all 40 dual A/B landed (2 hung agents retried). Sealed in parent merge above.
- **Audit CAP-004:** no R14 residual volume wave.

## 2026-08-05 - R12 residual dual wave (undualed R11 callees)

- Partition: `reviews/WAVE_2026-08-05_r12_residual_partition_map.md` (40 OWN agents R12-001…040).
- Candidates: undualed inventory-`full` callees referenced from R11 dual artifacts (skills/inventory/missions/interaction/input + STL leaves).
- Dual unique **2646 → 2686** (+40). All 40 dual A/B sealed (filesystem A∩B).
- Inventory promoted full→reviewed for R12 set (reviewed 81→121; full 17082→17042); none/raw/partial still 0.
- Terminal accounting remains true under list_functions 25671.
- Dual depth still incomplete (2686 ≪ 25671).
- Three hung agents (R12-002/016/024) killed and retried successfully.
- Parent merge: progress.json dual_ab_pairs=2686; RESUME/ACTIVE_WORK/COVERAGE_LEDGER sealed.

## 2026-08-05 - R11 residual dual wave (undualed HP callees)

- Partition: `reviews/WAVE_2026-08-05_r11_residual_partition_map.md` (40 OWN agents R11-001…040).
- Undualed inventory non-trivial callees of dualed HP managers (inventory/skills/missions/interaction/input).
- Dual unique **2606 → 2646** (+40). All 40 dual A/B sealed (filesystem A∩B).
- Inventory promoted full→reviewed for R11 set (reviewed 41→81; full 17122→17082); none/raw/partial still 0.
- Terminal accounting remains true under list_functions 25671.
- Dual depth still incomplete (2646 ≪ 25671).
- Parent merge: progress.json dual_ab_pairs=2646; RESUME/ACTIVE_WORK/COVERAGE_LEDGER sealed.

## 2026-08-05 - R10 residual dual wave (undualed HP callees)

- Partition: `reviews/WAVE_2026-08-05_r10_residual_partition_map.md` (36 OWN agents R10-001…036).
- Undualed inventory non-trivial callees of dualed HP managers (CRT leaves, STL helpers, inventory/craft/mission UI).
- Dual unique **2570 → 2606** (+36). All 36 dual A/B sealed.
- Inventory promoted full→reviewed for R10 set (reviewed 5→41; full 17158→17122); none/raw/partial still 0.
- Terminal accounting remains true under list_functions 25671.
- Dual depth still incomplete (2606 ≪ 25671).
## 2026-08-05 - Live inventory gap close (terminal accounting)

- Re-measured live Ghidra via `list_functions_enhanced`: **25671** unique (not `get_function_count` 26263 inflated stamp).
- Diff vs `inventory.jsonl` found **5** missing live VAs; closed all:
  - `0x0051b850` `CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget` (reviewed; trio filled)
  - `0x00537d10` `CNDHashNode_NonOwning_scalar_dtor_Inferred` (reviewed)
  - `0x00573900` `InventoryGrid_SetSecondaryOwner_Inferred` (reviewed; mega dual prior)
  - `0x008612b0` `UI_InventoryWindow_OnItemClickDispatch_Inferred` (new dual + full)
  - `0x008c50f4` `Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred` (new dual + full)
- Inventory **25671** accounted: full 17158 + trivial-batch 8508 + reviewed 5; `none`/`raw`/`partial` = **0**.
- Dual unique **2568 â†’ 2570** (+2 new duals). Liveâˆ’inventory gap **0**.
- `terminal_full_coverage=true` under list_functions universe; dual depth still open.
- Tests: `docs/reconstruction/experiments/test_inventory_terminal_accounting.py` (3 passed).
- Scratch proof: `{SCRATCH}/live_ghidra_count.txt`, `inventory_status_dist.txt`, `dual_unique_count.txt`, `live_inventory_gap_after.txt`, `test_inventory_terminal_accounting.out`.

## 2026-08-05 - MEGA-005 final residual seal (parent MERGE-MEGA-005)

- Final open mega residual dual landed: `0x00589bc0` `Skill_HB_ApplyHeatDelta_Inferred` (accept-with-gaps).
- Dual A/B present: `A_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` / `B_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md`.
- Dual unique A/B **2567 â†’ 2568** (+1). Mega sealed **140/140** complete.
- Skills-abilities mega dualed **36 â†’ 37**; open residual **none**.
- Ledgers lockstep: VERIFICATION_MATRIX + NAMING_REGISTRY + skills-abilities + WORK_QUEUE / RESUME / ACTIVE_WORK / PROJECT_STATE / COVERAGE_LEDGER / progress.json.
- **terminal_full_coverage=false**. No runtime Confirmed.
- OWN dual report: `docs/agents/task-dual-ab-00589bc0-mega-005-report.md`.
- Final merge report: `docs/agents/task-merge-mega-005-final-report.md`.

## 2026-08-05 - MEGA residual dual seal (parent MERGE-MEGA)

- Nested undualed callees of dualed WQ-007/008/009 managers (EXP-M/I/S/X/GAP/D â†’ 140 VAs, OWN agents MEGA-001â€¦140).
- Units: inventory drag cleanup / craft batch count / stack concat / grid helpers; missions UseItem give-by-cbid / tracker / dialog / reward / objective gates; skills Skill_HB apply cascade (HP/shield/short/floater/multi-arg) + reschedule + UI target sort; interaction pick-list / soft-cast / area-query / PollBoundActions nested; input axis-park / ActionMap / keymap.ini / mission-UI thr-steer park; plus residual STL/UI leaves under dualed parents.
- Dual unique A/B **2428 -> 2567** (+139). Mega sealed **139/140** at first parent merge.
- Open residual at first merge: `0x00589bc0` MEGA-005 `Skill_HB_ApplyHeatDelta` (later sealed by MERGE-MEGA-005 â†’ 140/140 / dual 2568).
- ADV: `ADV_mega_spotcheck.md` **8/8 PASS** (depth-9 ADV already done).
- Ledgers lockstep: **139** in VERIFICATION_MATRIX + NAMING_REGISTRY + system maps (missions/inventory/skills/interaction/input).
- **terminal_full_coverage=false**. No runtime Confirmed.
- Partition: `reviews/WAVE_2026-08-05_mega_residual_partition_map.md`.
- Merge report: `docs/agents/task-merge-mega-residual-report.md`.

## 2026-08-05 - WQ-009 depth-9 residual dual seal (parent)

- Nested callees beyond WQ9K (20 VAs, OWN agents WQ9L-A...J + finish agents D2/H2/F-RPT).
- Units: isnil131 iterator++/erase-rebalance; out_of_range ctor; L/R rotate + max isnil31; RDTSC timer stamp; UI complete-dtor leaves (buffered teardown, clear owned, gfx window, text layout, refptr@294, nested layout); CVOGMenu CNDHash traverse-delete; StdList clear ESI; dialog child-hash teardown; shop list slot bind/orient helpers.
- Dual unique A/B **2408 -> 2428** (+20).
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + skills-abilities depth-9.
- STL/UI helpers noted under residual depth (not product skill English).
- **terminal_full_coverage=false**. No runtime Confirmed.
- Partition: `reviews/WAVE_2026-08-05_wq009_depth9_partition_map.md`.
- Merge report: `docs/agents/task-merge-wq9l-depth9-report.md`.

## 2026-08-04 - WQ-009 depth-8 residual dual seal (parent)

- Nested callees beyond WQ9J (20 VAs, 10 OWN-ONLY agents WQ9K-A...J; WQ9K-D restarted after hang).
- Units: uninit_copy trampoline; string destroy; erase-range free parents (isnil131/isnil2d); buynode/construct-empty shells; insert-or-find EBX; erase isnil31; UI complete-dtor chain (buffered/window/menu/dialog); CWndVehicle derived teardown; shop reindex; Class_00a733ec factories; L/R rotate isnil2d; uninit_copy Elem12.
- Dual unique A/B **2388 -> 2408** (+20).
- Independent ADV: erase/UI + tree/shop samples - `ADV_wq9k_spotcheck_*.md`.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + skills-abilities depth-8.
- WQ-007 skeptic machine-check: **16/16** matrix+naming+sysmap (0 missing). Proof: `wq007_force_repair_result.json`.
- Experiments **108 passed** x2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md`.

## 2026-08-04 - WQ-009 depth-7 residual dual seal (parent)

- Nested callees beyond WQ9I (20 VAs, 10 OWN-ONLY agents WQ9J-A...J).
- Units: PodCopy Elem12 + uninit_copy 0x28; UI complete dtors (CWndVehicle/WaypointIcon/Chatlog/Tutorial); MeshHost upload + ShopVeh swap; tree min/buyhead/predecessor/node-ctor/free-subtree; HkArray free; GfxParam lookup.
- Dual unique A/B **2368 -> 2388** (+20).
- Independent ADV: pod/UI + tree/mesh samples - `ADV_wq9j_spotcheck_*.md`.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + skills-abilities depth-7.
- WQ-007 skeptic force re-audit: **16/16** still present (matrix function rows + explicit index section; naming L406-421; sysmap L40-55). Proof: `wq007_skeptic_force_reaudit.txt`.
- Experiments **108 passed** x2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md`.

## 2026-08-04 - WQ-009 depth-6 residual dual seal (parent)

- Nested callees beyond WQ9H (20 VAs, 10 OWN-ONLY agents WQ9I-A...J).
- Units: FreelistSlabVector teardown; ConstructN/PodCopy; isnil21 insert-or-find + insert-rebalance + node ctor; POD placement 0x138; host CNDHash traverse teardown+recreate BL2; StdList incsizes; UI vehicle/widget scalar dtors; xform assign; field-block copy; CS init; ptr-vec shell ctor.
- Dual unique A/B **2348 -> 2368** (+20).
- Independent ADV: core freelist/insert/recreate + vector/list samples - `ADV_wq9i_spotcheck_*.md`.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + skills-abilities depth-6.
- WQ-007 skeptic: live line-proof all 16 residual duals already sealed (matrix L89-98, naming L406+, sysmap L42-55). No repair write required.
- Experiments **108 passed** x2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md`.

## 2026-08-04 - WQ-009 depth-5 residual dual seal (parent)

- Nested callees beyond WQ9G (20 VAs, 10 OWN-ONLY agents WQ9H-A...J; WQ9H-A restarted after hang).
- Units: CNDHash freelist/ctor/dtor/recreate 00a2c2* family; vector InsertN/ConstructN/PushBack (0x28/0xC/0x10); Map_EraseRange_C; InsertHint isnil21; Client frame tick env day-cycle; pending ghost TFID assign; tree iterator++/buynode/buyhead; POD construct 0x138; Escort reaction factory.
- Dual unique A/B **2328 -> 2348** (+20).
- Independent ADV: CNDHash family + vector/env samples - `ADV_wq9h_spotcheck_*.md`.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + skills-abilities depth-5; escort factory on missions map.
- WQ-007 skeptic re-audit **16/16 closed** (matrix/naming/sysmap/cleans). Proof: `wq007_skeptic_closure_proof.txt`.
- Experiments **108 passed** x2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md`.

## 2026-08-04 - WQ-007 skeptic ledger re-verify (closed)

- Re-audited all **16** WQ-007 residual dual VAs: matrix **16/16**, NAMING_REGISTRY **16/16** (+ rename history), missions-progression entry table **16/16**, dual A/B **16/16**, named cleans **16/16** with 0 non-comment Ghidra paste markers on escort/markup rewrites.
- Matrix function rows **224** (not 37). Proof: scratch wq007_skeptic_closure_proof.txt.
- No ledger repair required; skeptic panel stale relative to sealed state.

## 2026-08-04 - WQ-009 depth-4 residual dual seal (parent)

- Explicit next residual after WQ9F: isnil29 free `0x004cb550` + SkillCNDHash complete dtor `0x0051de80` + insert preds/map/escort/sky/vector/CNDHash leaves (20 VAs, 10 OWN-ONLY agents WQ9G-A...J).
- Units: StdTree free-subtree isnil29 clones; SkillCNDHash complete dtor; predecessor + pair-key less; map operator[] TFID + find; aggro export to int-key map; map free/tidy isnil15_B; CVOGHBMissionEscort ctor; LookupClassDisplayName; env day-cycle sky blend; skillset/vector Ufill + insert-one strides; CNDHash 00a2c2e4 alloc/destroy.
- Dual unique A/B **2308 -> 2328** (+20).
- Independent ADV: free/dtor + insert/escort samples - `ADV_wq9g_spotcheck_*.md`.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + systems/skills-abilities.md depth-4 section; escort ctor also on missions map.
- Experiments **108 passed** x2. **terminal_full_coverage=false**.
- WQ-007 skeptic re-verify: all 16 residual duals already in matrix/naming/sysmap (closed).
- Partition: `reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md`.

## 2026-08-04 - WQ-009 depth-3 residual dual seal (parent)

- Explicit WQ9E residual freelist `0x004cb680` + undualed nested skill/cast/map callees (20 VAs, 10 OWN-ONLY agents WQ9F-A...J).
- Units: SkillCNDHash freelist release + scalar dtor; StdTree buynode Val24 isnil29 twins; Object aggro map decay/purge + TFID map find-live/erase-dead; StdTree erase-range isnil29; StdMap insert-or-find int/pair + insert-hint; Map free-subtree/erase-node/tidy isnil1d/isnil15 families + erase-range isnil15_B; host mode flag; convoy leader slot; world-clock sky blend.
- Dual unique A/B **2288 -> 2308** (+20).
- Independent ADV: freelist/buynode + map erase family - `ADV_wq9f_spotcheck_*.md`.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + systems/skills-abilities.md depth-3 section.
- Experiments **108 passed** x2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md`.

## 2026-08-04 Ã¢â‚¬â€ WQ-009 depth-2 residual dual seal (parent)

- Deeper undualed nested callees beyond WQ-009 depth (WQ9D): **20 VAs**, 10 OWN-ONLY agents WQ9E-AÃ¢â‚¬Â¦J.
- Units: SkillCNDHash destroy/alloc bucket table; Skill presence store + effect score; name-color palette + level-band; interaction-menu populate + crew host back-link; StdTree erase/insert rebalance isnil29 + Val28 families; Map erase node B; creature load skills (hash recreate site); Map free-subtree / erase isnil1d/isnil15 / tidy free-head.
- Dual unique AÃ¢Ë†Â©B **2268 Ã¢â€ â€™ 2288** (+20).
- Independent ADV: hash/presence + UI/erase samples Ã¢â‚¬â€ ADV_wq9e_spotcheck_*.md.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + systems/skills-abilities.md depth-2 section.
- Experiments **108 passed** Ãƒâ€”2. **terminal_full_coverage=false**.
- Partition: 
eviews/WAVE_2026-08-04_wq009_depth2_partition_map.md.

## 2026-08-04 Ã¢â‚¬â€ WQ-009 depth residual dual seal (parent)

- Highest remaining non-deferred depth after WQ-009 residual: **deeper undualed nested skill/cast callees** (20 VAs, 10 OWN-ONLY agents WQ9D-AÃ¢â‚¬Â¦J).
- Units: SkillCNDHash recreate/ctor; CVOGHBSkill Virus ctor + SharedOnHeartBeat; StdTree min/max/Lrotate/Rrotate isnil@+0x29; Map_EraseRange twins; VehicleCrew Insert/ClearMemberObject; Skill_ComputeEffectPresenceFlags; List_TraversalUnlock; Skill_HB OnEnd clear FX/cast binding; Rng_SampleUnitFloat; Client combat-chat emit; convoy Invite/Kick UI; entity nameplate color; world-clock quarter phase.
- Dual unique AÃ¢Ë†Â©B **2248 Ã¢â€ â€™ 2268** (+20).
- Independent ADV: WQ9D-A (SkillCNDHash), WQ9D-B/C (Virus ctor + SharedHB), WQ9D-I (combat chat + convoy UI) Ã¢â‚¬â€ see ADV_wq9d_spotcheck_*.md.
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + systems/skills-abilities.md depth residual section.
- Experiments **108 passed** Ãƒâ€”2. **terminal_full_coverage=false**.
- Partition: 
eviews/WAVE_2026-08-04_wq009_depth_partition_map.md.

## 2026-08-04 Ã¢â‚¬â€ WQ-009 residual dual seal (parent)

- Highest remaining non-deferred WQ after WQ-008 residual: **WQ-009** skills-abilities (priority 93). Entry cast managers dualed; dual residual nested callees (20 VAs, 10 OWN-ONLY agents WQ9R-AÃ¢â‚¬Â¦J).
- Units include: RNG unit-table window (status-effect seed), VehicleCrew_ContainsMember, TFID copy @+0x228, Virus OnHeartBeat, world-pickup type gate, hostile target cycle/select-nearest, TFID resolve vtbl+0x1dc, clonebase skill trio + skill-hash recreate, factions ensure/lookup, Object_OnDeath, material bank bind/fill (cast neighborhood), ServerCreateFromPacket.
- Dual unique AÃ¢Ë†Â©B **2228 Ã¢â€ â€™ 2248** (+20).
- Independent ADV: WQ9R-A/B/J spot-checks (see `ADV_wq009_spotcheck_*.md`).
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + systems/skills-abilities.md residual section.
- Experiments **108 passed** Ãƒâ€”2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq009_residual_partition_map.md`.

## 2026-08-04 Ã¢â‚¬â€ WQ-008 residual dual seal (parent)

- Highest remaining non-deferred WQ after WQ-007 residual: **WQ-008** inventory-transfer (priority 94). Entry grab/drop/equip dualed; dual residual high-mention nested callees (20 VAs, 10 OWN-ONLY agents WQ8R-AÃ¢â‚¬Â¦J).
- Units include: InventoryGrid MoveFootprint/CanPlaceItem/RemoveByCoid/RemoveAtXY/SetOwner/SetDirty/ScalarDtor; type-0x1a SimpleExchange/Craft; CVOGStore TryAddItemQty; RecvOpenAvailableGadgetResponse `0x20A8`; craft host TFID bind; RE/tinker/gadget hover tooltip; UseInventoryItemByCoid; commodity cost sum; QB CanCastBoundSkill; hardpoint skill flag-0x200 cast; UI OnCommand class-8; outpost schedule entry helper; nearest-world-obj CBID filter (locker gate).
- Dual unique AÃ¢Ë†Â©B **2209 Ã¢â€ â€™ 2228** (+19 net; one reconfirm).
- Independent ADV: WQ8R-B/C/G spot-checks (see `ADV_wq008_spotcheck_*.md`).
- Ledgers lockstep: **all 20** in VERIFICATION_MATRIX + NAMING_REGISTRY + systems/inventory-transfer.md residual section.
- Experiments **108 passed** Ãƒâ€”2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq008_residual_partition_map.md`.

## 2026-08-04 Ã¢â‚¬â€ WQ-007 residual dual seal (parent)

- Highest-priority non-deferred work item **WQ-007** (missions-progression, priority 96): dual residual undualed callees on MissionDialog / journal / GiveMission / CompleteObjective call chains (16 VAs, 8 OWN-ONLY agents WQ7R-AÃ¢â‚¬Â¦H).
- Units: multi-active mission tip; dialog header caption; response-button build/clear; markupÃ¢â€ â€™richtext; token expand `[$name/class/race/credits/level]`; race/class display names; mselect entry ctor; dword vector push/insert; key-code display + action-map bind format; UseItem apply (GiveMission residual); MissionEscort OnHeartBeat (CompleteObjective/FailMission residual).
- Dual unique AÃ¢Ë†Â©B **2193 Ã¢â€ â€™ 2209** (+16).
- Independent ADV: WQ7R-A PASS, WQ7R-C PASS, WQ7R-D PASS.
- Ledgers lockstep: **all 16** in `VERIFICATION_MATRIX.md` (+ summary 53 rows); **all 16** in `NAMING_REGISTRY.md` (2026-08-04 batch + rename history); **all 16** entry points in `systems/missions-progression.md`.
- Clean rewrites (not Ghidra paste): `CVOGHBMissionEscort_OnHeartBeat.cpp`, `MissionDialog_ParseMarkupToRichText_Inferred.cpp` (+ FUN twins).
- Experiments **108 passed** Ãƒâ€”2. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wq007_residual_partition_map.md`.

## 2026-08-04 Ã¢â‚¬â€ multi-agent wave 38 merge (parent)

- Concurrent OWN-ONLY duals (33 agents W38-AÃ¢â‚¬Â¦AG, **65 VAs**): undualed callees of dualed managers Ã¢â‚¬â€ AssPreloader helpers (ext bucket, pop-front, erase), stoChunkReader text/binary readers + soft-skip, GBOD nested (phyBoundingBox, phySkeleton, CPDefinition/MorphWeight, bitvec, vector resizes), GfxDevice_Reset nested chain (effect factory lost/reset, buffered views, IB/VB factories, texture factory, stats monitor, present log, state cache), EffEffect find-param/create-load, media preload string vec, CSoundManager `.ogg`/`_lxx.ogg` append, map/tree iterators.
- Dual unique AÃ¢Ë†Â©B **2128 Ã¢â€ â€™ 2193** (+65).
- Independent ADV spot-checks: W38-H PASS-WITH-FINDINGS (float3 stream order fixed to +0x14Ã¢â€ â€™+0x20Ã¢â€ â€™+0x00), W38-Q PASS, W38-AG PASS.
- Experiments **108 passed** Ãƒâ€”2. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wave38_partition_map.md`.

## 2026-08-04 Ã¢â‚¬â€ multi-agent wave 37 merge (parent)

- Concurrent OWN-ONLY duals (32 agents W37-AÃ¢â‚¬Â¦AF, **63 VAs**): high-mention nested callees of dualed manager paths + wave36 residual PalToolNoMap pair (`0x0098fd80`/`0x0098df00`); includes AssPreloader drain/ctor, stoFileOSFile_Open, MissionTree media preload walk, GuardedVector dtor, StdVector Elem28/BasicStringW/RcElem28 helpers, CNDHash reclaim twins, GfxBody GBOD unserialize, GfxDevice_Reset, List_RemoveAll, loot tally, Object unload entry, Xform/scale, map insert/find, and related workers.
- Dual unique AÃ¢Ë†Â©B **2065 Ã¢â€ â€™ 2128** (+63). Wave36 residual duals closed inside W37-A.
- Independent ADV spot-checks: W37-A (PASS-WITH-ISSUE Ã¢â‚¬â€ stage-2 WireColor prose corrected to green), W37-C PASS, W37-E PASS (+ sealed empty DDS quality suffix).
- Experiments **108 passed** Ãƒâ€”2. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-08-04_wave37_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 35 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W35-AÃ¢â‚¬Â¦T, 40 VAs): GuardedVector EraseFirstEqual ThiscallRange; AssPreloader ProcessKeyRingStep; CircularSentinel Alloc0x14/0x10; NDResourceCache Ctor + CompleteDtor; Class 00aa05cc Ctor; Sto UnserialFactoryMap A/B GetInstance; NestedHash0x10 StaticOnceGet; HostPtrTable12 Bootstrap EDI; GfxMesh BuildNonInteriorEdgeIB; Host DrainPendingNfxEventQueue; RefCountedPtr3Flags DefaultCtor; StdList AllocSentinel 0x30; GlyphCache PlacementCtor; FourCCFnPtrMap TryInsert; Palantir BaseCtor + ResetDevice + ScalarDeletingDtor; PalantirSub10 DestroyOwnedPtrVecAndComUninit; StdUninitCopy/FillN/CopyBackward Pod28; Pod28 FillAssign; StdVector Resize Pod28; RcElem28 CopyCtor + UninitializedCopy + FillN + DestroyRange + AssignFill + AssignBackward; StdVector Resize/InsertOne RcElem28; GfxDevice Ctor; HostAux40 Ctor; Host34/54 NestedHash0xC Ctors; StdVector UninitializedCopy/FillN Elem28.
- Dual unique AÃ¢Ë†Â©B **1987 Ã¢â€ â€™ 2027** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave35_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 34 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W34-AÃ¢â‚¬Â¦T, 40 VAs): Fs DeleteDirTreeRecursive; SpeedTreeRT ComputeTree; IdvFileError Ctor MsgBracketErrno; AssPathList ListBasenames FilterPush; EffDeviceEffect BindEffectParams; StdString OperatorPlus Char; NestedHashBag Ctor family (0x28/0x14/0x10/0x30/0xC/0x18 sentinels); Mem FillDwordN FromSrc; HeadBag Ctor Sentinel0x14; BasicString UninitializedFillN; Fs ReadPathListFileToStringVec; StringTable FindOrIntern u16; CNDAssetStringTable Unserialize; StringVec PushBackIfAbsent EnsureTrailingDirSep; StringVecShell TidyAndClearGlobal; Palantir CompleteDtor; BasicString CopyBackward 0x1c; GuardedVector EraseRange Thiscall + ResizeZeroFill; ParticleFluidPhase Ctor + InitFluidBumpChild + CreateFluidParticles + CreateLiquidChild; AnimEventVec InsertN; StdVector InsertN Pod28/RcElem28/Elem28/CountEcx/ValueEdx/BasicStringW; StdVector AssignFrom BasicString; CNDUIWndBuffered Ctor; PalantirEnv TearDefaultLights.
- Dual unique AÃ¢Ë†Â©B **1947 Ã¢â€ â€™ 1987** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave34_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 33 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W33-AÃ¢â‚¬Â¦T, 40 VAs): StdTree Tidy FreeHead Bare Val12; Class 009c7948 ScalarDeletingDtor; CircularSentinel Alloc0x28; PtrVecShell InitFill; Fs PathIsDirectory Stat + ListDirBasenames; StringVec PushBack + Tidy; Fs ExpandPathSpecToStringVec; AssPackManager AddDirectoryTree + ExtractPackEntry + AddOrReplaceFile; StdString OperatorPlus Cstr/String; StdUninitCopy/FillN BasicString; StdVector DestroyRange/UninitializedCopy BasicString; BasicString FillAssignRange + CopyBackward Thunk; StdVector Elem28 Size; GuardedVector RingAssignForward + RingFillFromPtr + RingAssignBackwardChecked + Resize Thiscall + AssignLinearRangeAt; AssPreloader EnqueueEligibleFromCacheKeySpan + RetireStaleNeverLoaded; PodU32U8 StoreByValue; SideHost PushKeyFlag0/1; AssManager EnsureAssPreloader; AssPack ReleaseBlock Coalesce; Fs Path EnsureExtension; ListTrackedCtx ClearDestroyAndReset; PoolHost Acquire0x40; HostAux14 Ctor; ParticleFluidPhase Init; CVOGEnvironmentDistort/Reflect Enable.
- Dual unique AÃ¢Ë†Â©B **1907 Ã¢â€ â€™ 1947** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave33_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 32 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W32-AÃ¢â‚¬Â¦T, 40 VAs): BasicString CopyEnsureTrailingDirSep; StringVec InsertOne; StdVector InsertN BasicString; StdTree Tidy FreeHead Val12 + EraseRange Val12; Class 009c7948 CompleteDtor; AssResolverA NestedHash Ctor; Fs DirRecurseCollectLeafPaths; AssResolverCore HeadBag Ctor; AssPackManager CompactPackFile; GuardedVector AssignDwordIfNonNull + InsertN Thiscall + PushBackLocked Thiscall + InsertRange + InsertRange Thiscall; MissionHost CollectMediaPreloads; Object CollectAllGraphicsPreloads; Weather NfxListFillOrActivate; AssPreloader TryPreloadChildAssets + EnqueueKeyAndDeps + ExpandDepsAndEnqueue + PreloadWorkerLoop; FillPreloadList; PreloadDep CollectTransitiveKeys; Pod8 CopyIfNonNull + PodU32U8 StoreSplit/CopyIfNonNull; GuardedVector PushBackLocked Stride2 U32U8; AssManager SweepTrackedAssets; HostBase DefaultCtor + EnsureAuxPtrs; StdList AllocSentinel 0xC; ListTrackedCtx Ctor; PalantirEnv ApplyDefaultScalars + RebuildDefaultLights + InitEffectTextures; WaterPhase Ctor + RegisterToken; CVOGPhaseDistort ctor; CVOGEnvironmentReflect ctor.
- Dual unique AÃ¢Ë†Â©B **1867 Ã¢â€ â€™ 1907** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave32_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 31 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W31-AÃ¢â‚¬Â¦T, 40 VAs): StdTree FreeSubtree Val12 + StdTreeHost PtrVal CompleteDtor; OwningSList ClearDestroy ScalarDtor; EmptyDtorStub; GfxBody CompleteDtor; Host EnsureRegionCellOwned + ClearListTrackedOwnedInRect; Ctx ClearListTrackedOwnedAtScaledXY; Class 009c7938 ScalarDeletingDtor; StringVec PushFront EnsureTrailingDirSep; Palantir StartPreloadThread; ResourceCache SetField10AndConfigure; AssManager ResolverA Ctor + AssResolverCore Ctor; AssPackManager OpenPackFile; Client CompileEffectsBootstrap; GuardedVector PushBack/Front Thiscall + PushBack Stride2 U32x2/U32U8; AssPreloader EnqueueEligibleFromRing + IsKeyTrackedRecursive; Elem0x28 DefaultCtor; MapChild RebuildHostElemsAndIntGrid; CNDHash FreeBuckets twins; Host ResetHashQueuesVectors; StdMap LowerBound Tfid Isnil29; GfxView Ctor + SetNear; PalantirEnv Ctor + InitPhases; EnvSlot SetActiveBumpGen; Client InitRenderEngine; ObjectCsList CompleteDtor + Base ScalarDeletingDtor + ClearDestroyNoNode4; CVOGCharacter TryClearMissionCounterIfPositive; Client DebugCmd AddDisciplinePoints; Object UnloadGraphics.
- Dual unique AÃ¢Ë†Â©B **1827 Ã¢â€ â€™ 1867** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave31_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 30 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W30-AÃ¢â‚¬Â¦T, 40 VAs): GuardedVector GrowBlockMap Thiscall/Stride2 + ContainsFirstEqual + PopFront + PopBack + PushBackLocked; Owner ClearDestroyGuardedPtrDequeAt28; AssManager InitPrecompileAndResolvers; PerfStatRings CommitAndTrim; StdList AllocSentinel 0x18; Client InitPalantirViewBundle; ObjectCsList ClearDestroy; CNDHash Recreate 009cb45c/009cb450; CVOGSpawnPoint ActivateFromStream; Object SetMissionStateFx; CVOGCharacter SetMissionCounter; PhysHost AttachObject + IslandHost Ctor; WorldObj UnbindOrDefer; Object FactoryRegisterListed + CompositeStopTypeF MIEntry; StdTree EraseAndRebalance Val12 + StdMap InsertOrFind IntKey peers; CrazyTaxi AccumulateLegTime; Client TryInventoryAutoMergePartialStacks Notify; Obj 009d95b4 ScalarDeletingDtor + DefaultCtor + CtorPopulate; StdTree Clear PtrVal Vtbl0C; ListTrackedObj CompleteDtor; Host Clear/Rebuild Elem0x28Array; Emitter ReleaseToFreelist; ObjectMotion SlotEmptyDtor + HostTeardown; CVOGHBAICreatureBase PathlessIdleRoam; Object TFIDMapLookupOrRelatedMatch; CVOGHB SlewFacingYaw OnHeartBeat.
- Dual unique AÃ¢Ë†Â©B **1787 Ã¢â€ â€™ 1827** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave30_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 29 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W29-AÃ¢â‚¬Â¦T, 40 VAs): GuardedVector InsertN + ClearAndSwap + PushFront + PushBack; StdDeque ThrowTooLong; AssManager RemoveResolver + ReleaseOwnedResolvers; Map TreeInsert Val12 EsiBuy; StdTree Dec Val12; InventoryGrid AutoMergePartialStacks; Elem0x28 CompleteDtor; Class 009c7a1c ScalarDeletingDtor + Ctor; Object SharedBase Dtor; Object 009d33c4 Ctor + ScalarDeletingDtor; Color ClampRoundPackBGRA; Env ApplyFogShaderAndReflect; Object FwriteColorFields; UI FormatObjectDifficultyTier; CNDHash AllocBucketTable twins; CVOGHBAI EngageSelectTargetFromOwnerTFID; StdMap FreeSubtree + Dtor + InsertAlways IntKey; Object TeardownSecondaryFxList + RemovePrimaryFxEntry; StopTypeF MIThunk; CVOGHB FixedPeriod1 ctor; CVOGHBActivatePlayer OnEnd + EndOrDestroy; StdTree OperatorIndex Val12; LinkPair QuickSort DualKey; PhysHost ReconcileLinkPairs; PhysMgr AttachBody; WorldObj UnregisterAndRelease; PhysHost MergeSortedPairList; WorldObj AttachRegisterHost + SnapshotHostRefsAndUnbind.
- Dual unique AÃ¢Ë†Â©B **1747 Ã¢â€ â€™ 1787** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave29_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 28 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W28-AÃ¢â‚¬Â¦T, 40 VAs): GuardedVector RingCopyElements + GrowAssignRangeCore + GrowBlockMap + RingAssignBackward + EraseFirstEqual + Resize + RingFillRange; BitStream HuffmanAlphabet CopyRange; Color LerpU8x3 + PackFloat4 Scale255 + LerpPackedARGB; Object ResolveTargetViaReaction; Object SetEnhancedStateFlag; CVOGHBActivatePlayer ctor; Object TeardownOwnedFxLists + StopTypeF ReloadEventVariant; Emitter UpdateTick; ObjectMotion SlotReleaseToFreelist; CNDHash Ctor 009cb45c + 009cb450; CVOGHB SlewFacingYaw ctor + CVOGHBAI ProfileType4 ctor; Object SetMode278 SelectFromTFID228; CVOGHBAI InvokeVtbl4c AimOffset Flag1; Class 009c7a1c CompleteDtor + Object 009d33c4 CompleteDtor; Obj BodyDtor SetVtbl DestroyStdListAt10; StdTree Inc/Min/Max Val12; StdMap EraseRange + InsertOrFind IntKey + InsertHint Val12; LinkPair CanonAndSort; LocalWorklist16 Init + Release; PhysSim LtBroadPhase; Map EraseRange Val12; StdTree Buynode Val12 EsiValue; StdMap InsertOrFind Val12 UintKey.
- Dual unique AÃ¢Ë†Â©B **1707 Ã¢â€ â€™ 1747** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave28_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 27 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W27-AÃ¢â‚¬Â¦T, 40 VAs): FUN_0090f490 + FUN_008335a0 (math callers); BitStream HuffmanTree CopyRange; GuardedVector RingCopyRange + EraseRange + GrowAssignRange; NDSpecialFX StopFinalize; ObjectMotion SlotListTick + AdvanceStage + ApplyStageParams + SyncChildPoseHF; Object ActivatePlayerEnqueueHB; Object ResolveStoredTFID Vtbl1dc + PhysModeFromStoredTFID; GameUtils ParseRagDollBoneCount; Object CacheAIProfileFields TypeMask; Object EnsurePrimaryHBAI FromAIProfile; CVOGHBAI ProfileType4 DoLogic; Math Float3 IsFiniteIEEE + QuatExtractForwardZ OutFirst; CNDHash Remove 009cc1f0; StdList Destroy FreeHead; COList ScalarDeletingDestructor + Constructor; CVOGObject ComputeOutcomeRolls; Phys CommitPairListStorage; LinkPair SortedDiffWalk; LocalWorklist Release; WorldObj ReattachLinksGuarded + RehomeLinksFromSnapshot; WorldMgr RebindAllObjects; Map TreeInsert Val12 EsiBuy; StdTree Erase/Insert Val12 family clones (004e4130, 00539210, 005399f0, 00567450, 00573250, 00573510, 005ae4e0, 005ae990).
- Dual unique AÃ¢Ë†Â©B **1667 Ã¢â€ â€™ 1707** (+40). Imports **201** / thunks **67**.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave27_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 26 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W26-AÃ¢â‚¬Â¦T, 40 VAs): Math Vec3NearlyEqual AbsRel + QuatNearlyEqual DoubleCover + QuatNormalize; BitStream HuffmanAlphabetEnsureCapacity + HuffmanTree EnsureCapacity + HuffmanAssignCodes; Perf QpcBeginNamed; WorldObj UnbindLinks + BindLinks; CVOGObject ApplyModeFlag RebindSwitchHBAI; Object SetTFID ApplyPhysMode Rebind; GameUtils createRagDoll; GuardedVector CopyAssign; NDSpecialFX List1e0 AnyFlag10 + LivenessDone; ObjectMotion SlotTick; Emitter SpawnOnIntervalTick; ThreadSafeObjectList ScalarDeletingDtor; CVOGSectorMap Destructor; COList Destructor; Object ApplySingleFxSlot NoSlotFilter ThenTeardown; NDSpecialFX Child ApplyFxToggle SlotFilter; CVOGObject FxPhysStartStop IfSlotNeg; Client CreateObjectFromCbidPacket + ProcessSectorUpdate; Material ReleaseAndNullField0x18; CVOGGraphicsBase PostLoadScaleAndSelectFx; Host AIProfileMap GetOrReset; Map LowerBoundFindByIntKey Isnil65; CVOGHBAI UpdateAimOffset; CNDHash ValueClearOwnedPtrs + Ctor 009ce1a0; StdTree Lrotate/Rrotate Val12; UI MissionJournal BuildMSelectChrome; TNL NetClassRepInstance Dtor; Client ApplyVehicleSwitch; CVOGCharacter TickUseObjectPending; CVOGHBPendingUseObject Stop + OnHeartBeat.
- Dual unique AÃ¢Ë†Â©B **1627 Ã¢â€ â€™ 1667** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave26_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 25 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W25-AÃ¢â‚¬Â¦T, 40 VAs): CVOGCharacter ResolveUseObjectPending; MapFloatTfid EraseNode; Client Camera Modes257 ChaseUpdate + ModeDispatchUpdate; ThreadSafeObjectList Dtor; OleDb EnsureColumnInfoAndEnterBindings; Object ApplyDualFxSlots SlotFilterWild; NDSpecialFX ForEachHostPtrTablePair ApplyFxToggle; Character SwitchVehicle; Vehicle ActivateHardpointWeapons; CNDHash ReclaimAll ValueOwning + AllocBucketTable; Map TreeInsertAndRebalance Val12; UI MissionJournal ApplyStatusCompleteLabel; Object SurfaceDistance3D; CNDHash scalar dtor 009cfa7c; Mission ComputeObjectiveXpAsFloat; atexit NetClassRep rpcMsgGuaranteedOrdered; Object PlayPickupSpecialFX; CVOGHBAICreatureBase DoLogic; VehiclePhys Mode2Helper Ctor; Drive CollisionListener PrepBodyContact; EmptyBase Ctor ReturnThis; Item GetCycleTimeMs Scaled; hkAnalogDI CopyStringByKey; Vector InsertN 0x10; Skill HB SpawnEntities ctor; RefCountedPtr DefaultCtor; Phys StackDesc ResetFlag0 Float1000; Net SockaddrIn InitZero; netAddress CopyAssign; _com_error ScalarDeletingDtor; DES BuildIPFPLookupTables; Snd UpdateSounds UpdateSoundRegions; GuardedVector AssignTo; stoChunk ConvertToInteger; stoChunkReader ReadTextToken + ReadQuotedTag; Math FloatNearlyEqual AbsRel; BitStream HuffmanBuildTables.
- Dual unique AÃ¢Ë†Â©B **1587 Ã¢â€ â€™ 1627** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave25_partition_map.md`.
## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 24 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W24-AÃ¢â‚¬Â¦T, 40 VAs): NDAssetImage ReleaseOwnedBuffers; NDSpecialFX BindHostRefreshAndWalkRelated; OleDb AllocCtxBlock; WorldObj RebindActivate; NDSpecialFX HostTick; ObjectMotion IntegrateStep; Client Camera DefaultModeUpdate; NDSpecialFX ForEachOwnedBit7 ApplyFxToggle; Object EntityBase Ctor; LogicUiEventQueue Resize; OleDb AllocBindingsBuf EnterBuild; CVOGSectorMap Constructor; Object SetRaceIdOwnerChain; Object DoFullInit; Skill InsertActiveCastBinding; CNDHash FreeBuckets; StdTree Buynode Val12; UI QuickBar AssignItemOrMacro / AssignItem; UI MissionJournal SelectMission / Row ApplySelection; CVOGCharacter TryEvalInteractObjectivesNearObject; CVOGRegionMissions ResyncMissionObjectives; MissionStagingTree EraseRange; CNDHash Dtor 009cfa7c; FreelistSlabVector dtor; SkillDef BuildFxMasterName; CloneBase Load; Tree RotateLeft/Right Isnil15; ActionManager NotifyListenersAndCompact; ActionHost RemoveReverseListEntry; Vehicle DeactivateHardpointWeapons; Client RecvObjectResolveWeaponReset 0x201c; WeaponHitResultVec PushBack; AnimSlot Ctor + BindResourceFromPath; ThreadSafeObjectList PopFront; Client ItemPickup AutoGatherTick; MapFloatTfid FreeSubtree Isnil29.
- Dual unique AÃ¢Ë†Â©B **1547 Ã¢â€ â€™ 1587** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave24_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 23 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W23-AÃ¢â‚¬Â¦T, 40 VAs): RefCountedSlot ReleaseAndClear; NDAssetImage WriteAlphaPlaneByte; LogicUiEventQueue InsertN; Tree RotateRight; OleDb BuildBindingsAllocRow; NDAssetImage TransferFields; UI QuickBarSlotButton AssignSkill; StdVector InsertN Dword CountEcx; StdList Incsize; Client FlushWorldObjectState; StdMap InsertOrFind isnil15; Client LoadSkillsFX; Drive CollisionListener PlayCollisionEffect; CLoadNode initSpecialFX; NDSpecialFX DeactivateClear; CVOGObject Tick; StdMap EraseIterator; ClientSpecialEvent Respawn TeardownAirlift; EntityHost ApplyNestedLocalPosition; UI AppendItemRequirements; Object EntityMidBase Ctor; Combat ComputeBaseCritChance FromHost; PhysSim LtSimulate Collide; CNDHash InsertDualKey; CVOGReaction ScanPendingDeliverAndRegisterLinks; RbTree InitEmptyHeader Node1c; Client UI MapView DrawMarkers/Entities FOV overlay; Math QuatInverseRotateDelta; Client Map RaySegmentHitDistance; ActionManager UnregisterAndRelease; GetModifierSkillID; NDSpecialFX ExpandVehicleHardpointSlots; CVOGHBBase ScalarDeletingDtor; Object IsLevelLessThan6; CVOGHBBase AppendRemainingText; CVOGHBSkillBase DefaultCtor; CVOGHBRespawnCharacter ctor; CVOGHBMissionPatrol ctor; LockedList TryAdvanceIterator Loot.
- Dual unique AÃ¢Ë†Â©B **1507 Ã¢â€ â€™ 1547** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave23_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 22 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W22-AÃ¢â‚¬Â¦T, 40 VAs): Combat ComputeCritChance; Skill ApplyBoundStatusMotionTable; StdTree IteratorIncrement isnil49; Object SharedBase Ctor; InventoryGrid CommitPlacementMap; Object WriteComposedMatrix; QuickBar RebindPageColumns; BitStream GrowForBits; StdMap string/int key InsertNodeAndRebalance; Ui WriteFormatColorD3d; UiWidget TeardownIfActive; Win32 ThrowLastErrorAsHresult; UiToast UninitializedCopy 0x98 (Ãƒâ€”2 helpers); CVOGObject JustCreatedInit; LogicUiEventQueue InsertOneGrowPath; Drive CollisionListener Contact; CVOGHBRecreateObject RecreateOwner; CVOGCreature SlewFacingYaw; CNDHash FreelistPop Node0x28; UI ItemDetailPanel Refresh; gfxVertexBufferImpl Allocate; Com BstrHolder Release; Com LoaderCtx NestedTeardown; SkillRow UninitializedFillN 0x934; OleDb RowBufZeroAndCreateAccessor; TNL GroupReactionCall UnpackData; StdTree IteratorDecrement; NDAssetImage TGA row decode / RLE / by-format; CxImage Create; stoChunkReader TextReadU32 + ReadU32 ModeDispatch; RbTree InitEmptyHeader; SkillSet UninitializedCopy 0x18; Phy CPConnectionPair ReleaseClear; Mem FillDwordN / MoveDwordRange ReturnEnd.
- Dual unique AÃ¢Ë†Â©B **1467 Ã¢â€ â€™ 1507** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave22_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 21 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W21-AÃ¢â‚¬Â¦T, 40 VAs): CVOGHBBase dtor + EndOrDestroy soft-mark epilogue; Object ApplyFxWithTargetBind; InventoryGrid RePlaceItems; Skill HB FireTail FxTargetAndPeriodStamp; BitStream writeString; HandlerTable58 FindById6c; CNDHash Insert 009ce0a0; StdDeque ThrowTooLong; Character ClearEquippedRaceItemTfId; Client IsLocalMissionJournalReady; CVOGCreature ctor; StdMap InsertWithHint IntKey; XmlAttr FetchParseLong StoreByteIfOk; Skill ApplyBoundStatusMotionIfPresent; Vehicle ApplyHardpointFireMask; Combat RollCritMultiplier; TimerHost GetTimeFloat; AnimSlot SetTime; CVOGObjective SetCompleteCount; TNL NetClassRepInstance Ctor; Mem CopyBytes; GfxVBHolder ReplaceAndAllocate; Rng Source ExtractU32; Mem Move200B Blocks; CSoundManager ProbeSoundFileExists; NDResource DecRef; HashMap FindIterator; Bounds AccumulateTransformedLocal; RbTree AllocEmptyNode 0x30; StdMap StringKey InsertOrFind; ActionMap TrySetSlotBind; Client TryBindActiveMissionTracker; UI MissionPanel SyncSlotVisibilityAndLayout; CDlgQuickBar CreateChildWidgets + CycleSelectValidColumn; UiHost FindTrackedPairNode + RefreshTrackedNodeWidgets; UI RefinePanel InsertCommodityListRow; NpcMissionDialog TeardownChildWidgetLists.
- Dual unique AÃ¢Ë†Â©B **1427 Ã¢â€ â€™ 1467** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave21_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 20 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W20-AÃ¢â‚¬Â¦T, 40 VAs): CVOGHB targeting-link complete dtor; Client AppFrameTick; SkillElementTypeMap TreeInsertAndRebalance; PhysSim MergeHosts; Outpost PreRecastBankWalk; MT19937 Extract; stoChunkWriter WriteU32; Outpost CaptureOutpost; phyBone shared install + qs copy; mission tracker HUD refresh; UI inventory panel message handler; StdVector ThrowTooLong twin; UiToast UninitializedFillN; Mem MoveDwordRange ToExclusiveEnd; Weapon SelectMultiTargets; FxCache ApplyWithNfxEnsure + EnsureMasterAndResolve; OLE IAccessor CreateAccessor free bindings; BitStream writeQuantizedSignedInt + readString; NDAssetImage Flip + FlipHorizontal; std::length_error ctor; StdList BuyNode; CVOGObject SetGfxBodyLink Mode1; StdMap FreeSubtree; Skill HB SpawnEntities Precheck; CVOGObject GetActivePositionPtr; Item CharacterMeetsUseReqs; Host ScreenToTerrainHitNotify; CsSList ContainsPayload; Skill ApplyMultiTargetHits; Client SelectHostileUnderScreenPick; HandlerTable FindById; CVOGHBBase EndOrDestroy hard unlink; InventoryGrid SortAndRepack; CVOGHBBase SetPartnerLink; Object RefreshSkillHash; SkillTree RemoveBySkillId.
- Dual unique AÃ¢Ë†Â©B **1387 Ã¢â€ â€™ 1427** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave20_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 19 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W19-AÃ¢â‚¬Â¦T, 40 VAs): MT19937 Seed; Vehicle UpdateWeaponHardpoints3; StdVector ThrowTooLong; StdFill DwordRange; Mem MoveDwordRange; Client DispatchUiEventQueue; CNDHash BucketChainTouchRepair; Profiler ScopeLeave; Object RegisterListed; Skill SpawnTemplateAndStartHB; CloneBase AllocAndLoadByType; Character HostModeGateForObjectV210; CVOGHBWakeupSkill ctor; targeting-link scalar dtor; Item SetCustomized + SumEquippedComponentValues; Map EraseNode; Client InteractPrompt SetTarget; CVOGCharacter SetLevelWithFlags; StdMap InsertOrFindByIntKey; Tree RotateLeft; CNDHash reclaim owning/non-owning variants; SkillElementTypeMap InsertOrFind; WorldCast setup+dispatch; PhysSim FlushPendingBodyPairs; Object PurgeSkillHBListChain; Map Tree Predecessor; Outpost UpdateBeaconShareRatio; Host ActionList Push; CVOGHBAIBase SetFloat; DES S-box + P-perm tables; stoChunkWriter WriteI32; stoChunkReader PeekChunkTag; NDResource Ctor; Client ApplyPairRelativeTransform; NDXml FinishLoadResult; StatusFlag GetDisplayName; Client SendInventoryEquipC2S.
- Dual unique AÃ¢Ë†Â©B **1347 Ã¢â€ â€™ 1387** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave19_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 18 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W18-AÃ¢â‚¬Â¦T, 40 VAs): stoChunk stream Ensure/ReadBytes/ReadU32; CVOGHBBase empty vfunc; CsSList append payload; Client SendGlobalPacket; SkillDefMap GetGlobal; Object LoadOrReplaceAnimSlot; OLE CommandExecute IRowset; NDResource default type token; CircularPtrBuf Grow; Math Matrix4x4 Set16; CSoundManager tick hard-kill/regions + RequestPlay + mission-complete sound; NDSpecialFX Ctor; Profiler ScopeEnter; Creature GetPerception; Client InitInstance; CVOGHBWakeupSkill Fire; cast-state teardown; CompleteRegionMissions; CNDHash reclaim/InsertAlways/unlink u64; MT19937 Twist; interact prompt refresh; Map ConstructIntKeyNode; Audio LinearGainToMilliBels; OwnedPtrTable Clear; Timer CalibrateTscPerSec; StdVector PushBack12 / Dword InsertN; hardpoint mode match; optional TRS matrix; character create apply attach vehicle; RB tree alloc empty node; skill HB spawn entities; Object ResolveCoid vtbl+0x1e8; AllocateNewObjectFromCbid.
- Dual unique AÃ¢Ë†Â©B **1307 Ã¢â€ â€™ 1347** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave18_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 17 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W17-AÃ¢â‚¬Â¦T, 40 VAs): dual-key list find; mission dialog control dispatch; Vec3_Copy; CVOGRegionMissions ctor; Client InteractWorldClickHub; Net SockaddrIn_Init; stoChunkReader LeaveChunk/readF32/soft-skip + writer indent + stream header16; GameData LookupCloneBaseByCbid; Object HasFlag8SelfOrLinked; Character TryEquipItem; UI DefaultMessageHandler; errReport Dispatch; MSXML NamedNodeMap GetNamedItemText; Client ClearObjectReferences; ClientCamera ApplyModeDistanceBand; NDXml GetLoaderSingleton; Creature GetTheory; Object EnqueueDeferredOnce; CVOGLootGenerator GetOrCreate; CNDHash freelist reclaim; CVOGHBToken OnEnd; Path GetFileName + PathMap HasBasename; Client DismissModalPrompt; UI QuickBar SetSelected; `_CxxThrowException`; Math CopyFloat4; Object GetTargetAccuracyBase; EmptyRet; Phys ActionBase ctor; Map InsertNodeAndRebalance IntKey; CVOGObjectiveRequirement ctor; Profiler TimerBlock/Zone ctors; Object ResolveTfIdVtbl1d4; Client TeardownGameplaySession.
- Dual unique AÃ¢Ë†Â©B **1267 Ã¢â€ â€™ 1307** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed** (fixed `FUN_004a0b90.cpp` undefined4 gate). Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave17_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 16 merge (parent)

- Concurrent OWN-ONLY duals (20 agents W16-AÃ¢â‚¬Â¦T, 40 VAs): weapon try-fire + apply-damage; CVOGPhysics apply point impulse; dword fill-n; loot catalog typeÃ¢â€ â€™row + RNG bias + int-range merge; vehicle paint color ensure; sector-map character-enter level index; combat floater copy range 0x38; locked-list insert tail; OLE walk active bindings; std vector insert-one; std tree alloc node 0x1c; CSoundManager stopSound/ctor/erase named record; circular ptr push 0x14; hash COID lookup; CVOGHBAICreatureBase::DoMovement; COM clear slot + ReleaseIfNonNull; stoChunkWriter WriteFormatted; NDSpecialFX instantiate + ParseXmlEventNode; MBCS from wide; interact SelectBestPickTarget; UseItem MatchTargetCore; CNDHash u64 bucket find; IsPlayerTargetingLinkAndDestroy; mission interact offer staging; `_com_raise_error`; Net SockaddrIn InitInvalid; netSocket GetPeerAddress + Address trivial dtor; Timer RDTSC seconds; character skill-bag upsert/reapply; UI toast construct-n 0x98; vector erase-range dword; FourCC dwordÃ¢â€ â€™std::string.
- Dual unique AÃ¢Ë†Â©B **1227 Ã¢â€ â€™ 1267** (+40). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave16_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 15 merge (parent)

- Concurrent OWN-ONLY duals on loot catalog residual, combat floater relocate, vehicle track/soft-pose/create-msg, sector equip leave/remove/paint, garage refine/filter, mission EnsureXml string twins + objective XML + continent markers, XML parse helpers, FreeBuckets/scalar dtors, COM/vector/world enroll, skill DB load nested OLE/COM, multi-hit combat nested, vehicle net skills HB vector residual, skill apply/math leaves.
- Dual unique A **1131 Ã¢â€ â€™ 1227** (+96). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave15_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 14 merge (parent)

- Concurrent OWN-ONLY duals on loot generate residual (profile/mod/quality/catalog/hit/deferred), medal table load + CNDHash recreate/insert, mission complete rebind/register, vehicle net map/deque, container grow/locale/COM, character hash recreate/dtor, combat floater/level-up residual, skill def tree/XML, mission staging tree, inventory COID residual, drive secondary fire/enter-world nested, net skills HB pack/unpack, UI hash recreate/gauge ctors.
- Dual unique A **1041 Ã¢â€ â€™ 1131** (+90). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave14_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 13 merge (parent)

- Concurrent OWN-ONLY duals on SpecialFX residual, multi-target combat apply, FxMaster catalog/XML load, radial force impulse, vehicle ghost net residual, kill-loot/credit/convoy chain, audio freelist/path/busy, CNDHash RemoveAll/AllocBuckets twins, skill RNG/string-pool, medal/reward complete path, equip nested melee/FX, container/list/vector helpers.
- Dual unique A **949 Ã¢â€ â€™ 1041** (+92). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave13_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 12 merge (parent)

- Concurrent OWN-ONLY duals on SpecialFX residual, weapon FX pack, CSoundManager family, select/garage UI, phys action lists, cast FormatFailure/CD map helpers, inventory cell/window/equip hooks, VehicleNet unpack + BitStream string cache, NDUI widget ctors, CNDHash ctor/alloc/removeAll, DB enter/leave for XP ensure wrappers, mission resource/event gates.
- Dual unique A **883 Ã¢â€ â€™ 949** (+66). Imports **201** / thunks **67** (pure IAT/E9 pools exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave12_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 11 merge (parent)

- Concurrent OWN-ONLY duals on weapon/FX fire chain, inventory sheet rebuild (lock/iterate/clear/collect page), select UI residual, combat-pool level scale, flipper HB + phys register, CNDHash remove/destroy/freelist family, mission pending-objective ensure + node dtors/integrity walk.
- Dual unique A **842 Ã¢â€ â€™ 883** (+41). Imports **201** (FF25 pool exhausted). Thunks **67** (E9 pool exhausted).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave11_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 10 merge (parent)

- Concurrent OWN-ONLY duals on GatherTargetsInArea chain, mission CNDHash insert twins, physics prepare/activate/setPosition, transform/ortho/cast-ray math, inventory sheet/hash UI, toast grow/locale, targeting HB vtbls, client input residual (unstick/HB park/select), VehicleNet soft pose integrate/apply, weapon fire helper, float-keyed target maps.
- Dual unique A **783 Ã¢â€ â€™ 842** (+59). Imports **188 Ã¢â€ â€™ 201** (pure FF25). Thunks ledger formalized (67 pure E9).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave10_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 9 merge (parent)

- Concurrent OWN-ONLY duals on DriveControlTick physics chain, HF sample, quat basis extractors, targeting HB, progress dismiss, mod-chip lookup, inventory sheet UI, locale/string pool, GiveMission toast/blob/hash, profiler internals, CNDHash insert/remove, skill-load insert.
- Dual unique A **745 Ã¢â€ â€™ 783** (+38). Imports **177 Ã¢â€ â€™ 188** (pure FF25).
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave9_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 8 merge (parent)

- Concurrent OWN-ONLY duals on DriveControlTick / RequestCast / Grab / ResolveTargets / Equip callees missing A/B.
- Dual unique A **701 Ã¢â€ â€™ 745** (+44). Imports **171 Ã¢â€ â€™ 177** (pure FF25).
- Highlights: world-pos ptr, physics angular/vector apply, gated local pos, HF sample/march, CVOGHBBase_Stop, SetSelectedTarget, Weapon fire flags, mod-chip use `0x202c`, random up-kick, timed progress bar, chat toast sink, NDError_Log (enable==1), Profiler enter/leave, SkillDef map materialize, vehicle equip spine, inventory sheet UI.
- Experiments **108 passed**. Inventory none=0. **terminal_full_coverage=false**.
- Partition: `reviews/WAVE_2026-07-29_wave8_partition_map.md`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent waves 6Ã¢â‚¬â€œ7 merge (parent)

- **Wave 5 residual closed:** `0x00504c70` setDrivingInputs/throttle, `0x00512870` EnsureQuestBaseCredits, `0x00571b80` InventoryGrid_RemoveItem dual-sealed.
- **Wave 6 duals:** UI CreateChildWidgets (Arena/Trade/CharSheet), NDUIWindow/NDXml load chain, stoChunk Begin/End/Open/readF32, NDSpecialFX, TimedAction, Respawn Update, AttrPointClick (0x205A), DES full Feistel chain, gfx GPCE/INDX/VERT, vog_LogMessage, AutoPatrol `0x00929ec0`.
- **Wave 7 duals:** BitStream quant float, EnterChunkScope, Object_ResolveFromTFID, VehicleNet_PackUpdate, EMSG Damage `0x2023`, TNL ByteBuffer/Socket, 17 hk vehicle components, UI tooltip stats, special-event ctors, COM helpers.
- **Trivial-batch:** imports **121Ã¢â€ â€™171** (+ pure IAT); thunks **56Ã¢â€ â€™67** (+ pure E9).
- Dual unique A **~613 Ã¢â€ â€™ 701**. Experiments **108 passed**. Inventory still none=0 / terminal **false**.
- Partitions: `WAVE_2026-07-29_wave6_partition_map.md`, `wave7_Ã¢â‚¬Â¦`.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 6 launch + wave 5 merge (parent)

- **Wave 5 merge (partial):** dual unique A **~613** (A files ~626); most wave5 map VAs dual-sealed; residual dual gaps at launch: `0x00504c70` throttle, `0x00512870` EnsureQuestBaseCredits, `0x00571b80` occupancy sibling.
- Inventory restamp: **25666** accounted (`full` 17158 + `trivial-batch` 8508, `none=0`). `terminal_full_coverage=false`.
- **Wave 6 launch:** ~35 concurrent OWN-ONLY dual agents on domain gaps (UI dialogs, NDXml/NDUIWindow, chunk IO, SpecialFX, TimedAction, Respawn, inventory swap log, DES chain, gfx buffers) + import/thunk trivial-batch expanders.
- Partition: `reviews/WAVE_2026-07-29_wave6_partition_map.md`.
- Honesty: dual ~613 Ã¢â€°Âª 25666; stamp Ã¢â€°Â  dual depth; do not claim complete.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 5 launch (parent)

- Concurrent OWN-ONLY duals on named high-priority missing A/B (HBSkillListener, Outpost cast, TFID, CNDHash, quest tables, HB list, inventory stack/broken, mission map helpers) + CRT/thunk body-proven trivial-batch agents.
- Partition: `reviews/WAVE_2026-07-29_wave5_partition_map.md`.
- Terminal bar unchanged: dual depth Ã¢â€°Âª live 25666; stamp Ã¢â€°Â  complete.

## 2026-07-29 Ã¢â‚¬â€ verification panel + wave 4 (parent)

- Verification package: multi-agent partitions, sample wave3 trio **8/8 PASS**, ledger honesty, experiments **96 OK**.
- Live Ghidra count **25666** (legacy 26256 stale); inventory **25666** accounted (
one=0); dual A/B **~600** Ã¢â€°Âª universe.
- Terminal full coverage remains **false**. Plan Deviations restored terminal bar.
- Wave4 concurrent duals: CastAfterPrompt, accuracy chain, equip arm, inventory COID/list, journal ready, staging tree, fire/heat, camera apply, item pickup 0x2055, HideÃ¢â€°Â Flush, category CD remaining, etc.



## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 3 merge (parent)

- ~40 concurrent OWN-ONLY duals on high-priority callees missing A/B. Dual pairs ~560Ã¢â€ â€™~586.
- **UF-010** invoker sealed: `FUN_007fca10` Ã¢â€ â€™ vtbl+0x440 Ã¢â€ â€™ Flush; **UF-011** sealed: no +0x650 clear; cancel can flush unfilled 0x206E.
- New duals include: CanPlace, FindFreeForItem, Drop hit-test, Turn-in ready, staging map, region missions getter, Cast-block, PromptTarget, UseInventoryItem 0x2045, Chat 0x2021, primary weapons, max-speed, SetDriveAxes, Kill_Precheck.
- Experiments: 76 OK. Honesty: deep duals Ã¢â€°Âª 26256; stamp Ã¢â€°Â  dual depth.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 3 launch (parent)

- **Mandatory concurrency:** ~40 OWN-ONLY dual agents on high-priority callees missing A/B (flush UF-010/011, mission/skill/inventory helpers).
- Partition: `reviews/WAVE_2026-07-29_wave3_partition_map.md`. Parent merges ledgers only.
- Honesty: inventory stamp Ã¢â€°Â  full dual depth; finite run = durable dual advance + cold resume; remaining deep duals Ã¢â€°Âª ~26256.

## 2026-07-29 Ã¢â‚¬â€ multi-agent wave 2 merge (parent)



- **~60 concurrent residual dual agents completed** (skills / input / inventory / interact / missions) + wave1 relaunches (NPC TryCast, QB Activate, FlushPrepared).

- **UF-013..017 closed** (static doc lag); **UF-007 sealed High** (MoveToTarget Ã¢â€°Â¡ SetSteer `0xC7`); **UF-010 invoker sealed** (Flush vtbl+0x440 via FUN_007fca10); UF-006 label still open; UF-011 cancel flush open.

- High dual seals include: ValidateTarget AL; FormatFailure table; UseObject `0x2072`; IfInteractable; Grab/Drop pack; FindFree/Place index; Collect/Deliver +0x23; Prerequisites; Prepare/Flush/UiModal; CompleteObjective; Recv paths; LocalCast G0Ã¢â‚¬â€œG9; Resolve outFlags 1/2; Filter 4/8/0x10; Range bit2; hardpoint TFID; PushDriveAxes; SetSteer/Long/HB; naming scan 0 conflicts.

- Honesty: deep dual units Ã¢â€°Âª 26256; runtime only with Launcher approval. Experiment suite Ã¢â€ â€™ scratch `recon_experiments.txt`.



## 2026-07-29 Ã¢â‚¬â€ DriveControlTick camera look-offset residual (strengthen)



- **OWN camera only** on `Client_Input_DriveControlTick` `0x009223b0` / `aa_009223b0`: dual A/B `*_camera_refresh.md` strengthened (not full re-dual; soft-steer dual body untouched).

- Separation sealed High on four axes: storage / gate / value domain / consumer; SECTION 7 bind-site interleave matrix; soft look Ã‚Â±0.2 (`local_d4`) Ã¢â€°Â  soft steer Ã‚Â±0.5 (`+0x618`).

- Live re-decompile + re-`read_memory` (0.03/0.2/5/11 + alt floats). Function record + `systems/input-drive-control.md` + UF-003 partial + scratch `tmp/a_camera_dct.md`.

- **No** WORK_QUEUE/RESUME/ACTIVE_WORK. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ mandatory multi-agent wave 2 launch (parent)



- **~60 concurrent residual dual agents** with isolated VA ownership across skills / input / inventory / interact / missions + meta doc-lag (UF-013..016) + naming scan.

- Wave1 still finishing: NPC_TryCast `0x005d1280`, QuickBarActivate `0x00921b50`, FlushPrepared `0x008ab8f0`.

- Parent owns merge of `WORK_QUEUE` / `RESUME` / `UNRESOLVED_FINDINGS` / matrix; children do not edit those.

- Honesty: inventory stamp ACCOUNTED 25664 Ã¢â€°Â  deep dual-verified depth; continue priority residual only.



## 2026-07-29 Ã¢â‚¬â€ UF-016 doc lag note (parent meta)



- Stale same-day CHANGE_LOG bullets that said abandon modal Yes/No pairing "Probable" are superseded by UF-009 High seal (EAX 0x4e46 / stack 0x4e47). Do not re-open UF-009 from those log lines.

- Parent multi-agent wave continues residual duals; inventory stamp Ã¢â€°Â  full dual depth.



## 2026-07-29 Ã¢â‚¬â€ Client_RequestCastSkill dual residual (`aa_00941590`)



- **OWN ONLY** `0x00941590` / `Client_RequestCastSkill`. Scratch: `reviews/a_00941590.md`. **No WORK_QUEUE/RESUME.**

- **Sealed (asm):** packet `+0x18 skillId` = formal stack `nSkillId` (decomp false-omitted store); Resolve third arg = `&seedTfid` not `&nSkillId`; HB `__thiscall(entity, skill, chargeMs)` Ã¢â‚¬â€ `unaff_EBX` phantom; FX vtbl+0x238 arg2 = skill id Ã¢â‚¬â€ `unaff_retaddr` phantom; charge forced 0 on this path.

- Role seal: `client+0xe04` world/sim object + `+0x7e` optimistic-HB gate (product type name open). Dual builders vs QB activate documented.

- Dual A/B + function record + clean pack plate + matrix + skills map. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Client_ShowModalPrompt dual residual (`aa_007fdfb0`)



- **OWN ONLY** `0x007fdfb0` dual residual. Scratch: `reviews/a_007fdfb0.md`. **No WORK_QUEUE/RESUME.**

- Sealed OK/Cancel widget bind **High**: `CDlgPopup` (`i_d_pop`) children `CNDUICtrlButton` at `+0x550` OK / `+0x554` Cancel; program via `FUN_008a7150`/`FUN_008a7100` (`vtbl+0x74` Ã¢â€ â€™ `button+0xec`); asm `MOV EDI,EBP` before Cancel.

- `flagA` Ã¢â€ â€™ blocker chrome (`FUN_008a7090` / `panel+0x530`); `flagB` unused in body.

- Dual A/B + function record + clean plate + matrix row + UF-009 note. **No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Client_UpdateMissionJournal residual dual (aa_008ae130)



- **OWN ONLY** `0x008ae130`: residual dual sealed Active/New id partition + callee roles.

- **`FUN_00568200` falsified as id-collect** Ã¢â‚¬â€ live body is tree **iterator++** (`is_nil` @ `+0x49`); journal site `LEA ECX,[ESP+0x14]`.

- **`CVOGReaction_FailMissionNotify` at this site** = Vector_PushDword only (no fail/mutation); dual LEA destinations Active `ESP+0x24` vs New `ESP+0x34`.

- **Partition:** hash `char+0x540` hit Ã¢Ë†Â§ `[node+0x8]!=0` Ã¢â€ â€™ Active; else New (same `char+0x50c` walk).

- Entry ctor `FUN_00829ec0` / XML `i_d_npc_2d_btn_mselect.xml`; widget ids `0x9c4f` base.

- Dual A/B rewritten; clean/annotated/function record; matrix; system map gap line; scratch `tmp/a_008ae130.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 Ã¢â‚¬â€ Client_RecvInventoryGrabResponse dual residual (`aa_00811be0`)



- **OWN ONLY** `0x00811be0` dual residual. **No WORK_QUEUE/RESUME. No Launcher.**

- **Dispatch Confirmed:** PacketDispatch `case 0x2035`/`0x2039` Ã¢â€ â€™ this VA; sole xref call `0x008159b0` (`MOV EBX,ESI; MOV EAX,EBP; CALL`).

- **ABI Confirmed:** prologue `MOV ESI,EAX`; packet `EBX`; clear `client+0xb6`.

- **Packet map sealed:** invType **`+0x18`** (asm `MOV DL,[EBX+0x18]` Ã¢â‚¬â€ decompiler omitted), count `+0x1c`, SplitFlag `+0x20`, split COID `+0x28`, success `+0x38`.

- **Simple arm not thin:** `FUN_0093d6e0` = cursor apply (item EAX, invType DL, client+count stack); grid remove inside helper.

- **Helpers:** `FUN_00512160` thiscall SetCoidIdentity on new stack; `FUN_007fc150` cursor UI clear Ã¢â€°Â  `DAT_00d1a8f6` (busy clear external).

- Dual A/B + function record + annotated + clean plate; matrix row; scratch `tmp/a_00811be0.md`.



## 2026-07-29 Ã¢â‚¬â€ CVOGReaction_GiveMission dual residual (`aa_005327c0`)



- Residual only (no WORK_QUEUE/RESUME; no clean wholesale rewrite): scratch `reviews/a_005327c0.md`.

- Sealed call-site this: FUN_0053c360 to +0x540 then optional **+0x544** (not same-hash double); FUN_0053c660 to **+0x530**; FUN_00538b20 remove +0x538; FUN_00538a40 tree +0x508.

- Helper roles High: CNDHash_Insert/Remove (strings), MissionDef_EnsureXmlLoaded (FUN_00547920 ECX=def), 0x30 blob init, AddActiveObjective 2-arg thiscall.

- Def **byte** gates: +0x130 obj count, +0xAC repeatable (-1), +0xF8 toast, +0x100 secondary insert, +0x168 XML loaded.

- Dual A/B + function record + annotated corrections; light clean plate comments only. **No Launcher.**





## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â dual residual `aa_005462b0` CVOGCharacter_CheckMissionRequirements



- **OWN ONLY** `0x005462b0` dual residual. Scratch: `reviews/a_005462b0.md`. **No WORK_QUEUE/RESUME.**

- Sealed: ABI **2-arg thiscall** (`RET 4`; one-push call sites); `+0x120`/`+0x124` = **RequirementsOred** / **RequirementsNegative** truth table; `+0x104`/`+0x108`/`+0x118` = Discipline / DisciplineValue / RequirementEventId; `FUN_0052ada0` char resource map `@+0x584/+0x588`; `FUN_005405e0` event-vector membership.

- Dual A/B refresh; function record; clean plate; matrix row; missions-progression dual line. **No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Client_Skill_ResolveCastTarget dual residual (`aa_0093b3a0`)



- **OWN ONLY** `0x0093b3a0` / `Client_Skill_ResolveCastTarget`. Scratch: `reviews/a_0093b3a0.md` (+ `tmp/a_0093b3a0.md`). **No WORK_QUEUE/RESUME.**

- **Sealed:** `FUN_004f8b80` ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred`; outFlags bit4/8 writers ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ filter `0x0054ff00` (consumer link); active-bind `pA` ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ `activeBindScratch` (asm Confirmed); sticky is **silent invalid**, not binding-TFID promote.

- Durable: clean/annotated/function record, dual A/B residual close, VERIFICATION_MATRIX, skills map. **No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â dual residual `aa_0052da30` CVOGReaction_FailMission



- **OWN ONLY** `0x0052da30`: sealed Notify **`ECX = char+0x560`** (asm `LEA ECX,[ESI+0x560]`), Notify body = **u32 vector push** (not teardown), end-quest triple `+0x564/+0x568/+0x56c`, per-caller drain table (S2C/`006508d0` yes; Patrol/Kill/`0060e800` no).

- Strengthened dual A/B + function record + annotated + clean plate; scratch `tmp/a_0052da30.md`; matrix open-issues cell; NAMING `charEndQuestIdVector`.

- Still open: dirty `0x10` readers, `FUN_005307e0` dual unit, runtime/bit-exact. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Client_ShowNpcMissionDialogUI dual residual (`aa_009438f0`)



- **OWN ONLY** `0x009438f0` dual residual strengthen. Scratch `tmp/a_009438f0.md`. **No WORK_QUEUE/RESUME.**

- Live Ghidra ÃƒÂ¢Ã¢â‚¬Â°Ã‚Â¡ raw; clean CF preserved. Sealed: **EAX mission-key** at three call sites (Recv always `EAX=-1` mode=1; HandleButton state3 `dialog+0x518+idx*8`; list `entry+0x500`); chrome mode **`dialog+0x510`** (`int*[0x144]` 1/2); turn-in flag **`dialog+0x64c`** via `FUN_008aa760` from `FUN_0052b420`; Prepare 0x206E chain.

- Distinct from HandleButton router **`+0x648`** (not written here). Dual A/B + function record + clean plate + matrix. Verdict **accept-with-gaps**. **No Launcher.**





## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Mission_ComputeObjectiveXp dual residual seal (aa_0059dde0)



- **OWN ONLY** `0x0059dde0` `Mission_ComputeObjectiveXp`: dual residual (map iterator, callers, exact-match, bias).

- **Map seal:** helpers `ret 8` thiscall(out,key); after call EAX=out-it*, `*EAX`=node*; key `+0xc`, payload `+0x10`; nil `+0x15`/`+0x1d`; exact key missÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢0; L-1 same node* (no double-deref). `unaff_EDI` noise.

- **Caller seal:** xrefs ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â CompleteObjective grant (+bias `0x00aaa6d0`=0.5001f); toastÃƒÆ’Ã¢â‚¬â€2 + `FUN_0051f510` presentation only. No advance path.

- Dual A/B ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ **accept-with-gaps**; function record + annotated + clean plate; matrix row. Scratch `tmp/a_0059dde0.md`.

- **No WORK_QUEUE/RESUME. No Launcher.**

## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Skill_GatherTargetsInArea dual residual (`aa_0058d330`)



- **OWN ONLY** `0x0058d330` `Skill_GatherTargetsInArea`. **No WORK_QUEUE / RESUME.**

- **Sealed:** gather-mode table CF for `param_8` (0/1/2/3/4/6/7/8/9/10/0xb) from body + `FUN_0058a810` + literal callers + `CloneBaseObjectType` (Veh/Cre/Char). Query flag ladder; pass-1 6/7/10; self allow; skill `+0x60c`/`+0x610` ABI via ResolveTargetList.

- English/PDB mode names remain **INFERRED**. Spatial helper renames out of ownership.

- Dual A/B strengthened; function record + annotated + clean plate; matrix; systems map. Scratch `reviews/a_0058d330.md`. **No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â dual residual `aa_0052da30` CVOGReaction_FailMission



- **OWN ONLY** `0x0052da30`: sealed Notify **`ECX = char+0x560`** (asm `LEA ECX,[ESI+0x560]`), Notify body = **u32 vector push** (not teardown), end-quest triple `+0x564/+0x568/+0x56c`, per-caller drain table (S2C/`006508d0` yes; Patrol/Kill/`0060e800` no).

- Strengthened dual A/B + function record + annotated + clean plate; scratch `tmp/a_0052da30.md`; matrix open-issues cell; NAMING `charEndQuestIdVector`.

- Still open: dirty `0x10` readers, `FUN_005307e0` dual unit, runtime/bit-exact. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Client_RecvInventoryEquip dual residual (aa_00813f40)



- **OWN ONLY** `0x00813f40`: opcode **0x203C**/size **0x40** sealed (sole PacketDispatch xref `0x0081597c`); framing **PUSH ESI + EAX client** (`56 8b c5 e8ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â¦`).

- **Hardpoint class map sealed:** ornament `FUN_004fe620` `+0x26c`; plant named; melee `FUN_004fe800` `+0x264`; weapon attach `FUN_004fe110`ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢`Vehicle_AttachWeapon`; **wheelset case 0x10** `FUN_004ff510`ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢`Vehicle_SetWheelset` `+0x258`; armor `FUN_00502180`ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢`Vehicle_SetEquippedArmor`. Prior ÃƒÂ¢Ã¢â€šÂ¬Ã…â€œwheelset not in switchÃƒÂ¢Ã¢â€šÂ¬Ã‚Â **falsified**.

- Local path: `FUN_00502e90` is full equip dispatcher (not UI-only). Dual A/B + function record + annotated + clean plate; matrix; inventory-transfer map. Scratch `tmp/a_00813f40.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â CVOGReaction_ResolveSkillTargets dual residual (`aa_0054c570`)



- **Asm seal:** `__cdecl` (skillId, rankPacked); map this `DAT_00b04734`; null = **miss** vs end `DAT_00b04738` (not "cached"); `new 0x630` + ctor `FUN_0054f3c0` + `REP MOVSD 0x18c` from `node+0x10`; rank via `Skill_SetRankAndReevaluate` (`RET 4`, store `+0x5f6`).

- **Falsified:** target-list interpretation; plate "already cached"; decomp `unaff_DI` rank arg.

- Dual A/B refreshed (**accept-with-gaps**); clean/annotated/function record; scratch `tmp/a_0054c570.md`; raw re-verify append. **No** WORK_QUEUE / RESUME. **No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â `aa_00534920` EvaluatePendingObjectives dual tighten



- **OWN ONLY** `0x00534920` `CVOGCharacter_EvaluatePendingObjectives` dual A/B tighten. **No WORK_QUEUE/RESUME.**

- **Sealed:** `FUN_0059d880` = objective **CompleteCount** getter `*(obj+0x164)` (body + `FUN_005468c0` `<CompleteCount>` XML dump). Collect: `(count!=0 && count<=success) || allTrue`, and `obj+0x138==0`.

- **Plate falsifications fixed in dual/annotated/clean:** continent gate polarity (`+0x7e != 0` **and** `+0xf6 == 0`); precheck does **not** skip eval (only action/LogicUI); deferred CompleteObjective force **0** after unlock.

- Caller context kinds documented (5 Money, 6 post-complete, 7 combat, 9/10, 0xb patrol). Open: `+0x138` English, flag names, sealed kind enum, runtime.

- Artifacts: A/B, function record, clean, annotated, raw version note, matrix, registry, systems map. Scratch `tmp/a_00534920.md`. **No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Client_RecvNpcMissionDialog residual dual strengthen (aa_00815070)



- **OWN ONLY** `0x00815070`: count width + opcode/framing dual residual.

- **Count sealed:** client loop bound is **u8** at `packet+0x18` (`CMP BYTE` / `MOVZX BYTE`); AutoCore i32 LE write remains OK for counts 0ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“255 (low byte used).

- **Opcode sealed:** S2C **0x206D** ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ sole `Client_PacketDispatch` case/xref call `0x00815af4`.

- **Framing sealed:** `PUSH EBP; MOV EBX,ESI; CALL` + `RET 4` stdcall (packet in EBX, not EAX).

- FUN residual **roles** for `FUN_004bb070` / `FUN_0052d8b0` / `FUN_0053fff0` / `FUN_0052c700` (product names open).

- Dual A/B strengthened; function record + annotated + clean plate; chain `reviews/CHAIN_2026-07-29_s2c_206d_npcmissiondialog.md`; matrix row; scratch `tmp/a_00815070.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â Kill_Eval dual residual seal (aa_00613910)



- **OWN ONLY** `0x00613910` `CVOGObjectiveRequirement_Kill_Eval`: dual residual from 2026-07-23 open gaps.

- **Asm seal:** `MOVZX slot@+8`; `CVTSI2SS required@+0x18`; progress `[state+slot*4+4]`; `COMISS` + complete unless progress < required; `RET 8`; param_2 unread; no stores/calls.

- **Provenance seal:** pure reader; writers are `RecvObjectiveState` `0x00809460` (0x2071 absolute `state[1..4]`) and `Kill_Precheck` `0x00613b50` (`+=` same layout; early-outs via vtbl+0x8 Eval). Filters not in Eval.

- Dual A/B ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ **accept** (runtime/diff open); function record + annotated + clean plate; raw re-verify append; matrix row.

- Scratch `tmp/a_00613910.md`. **No WORK_QUEUE/RESUME. No Launcher. No Precheck dual ownership.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Client_RecvFailMission dual residual seal (aa_0080b100)



- **OWN ONLY** `0x0080b100`: dual residual ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â opcode dispatch (UF-012) + register contract.

- **Opcode sealed:** S2C **0x20B2** ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ sole `Client_PacketDispatch` xref call `0x00815d97`.

- **Framing sealed:** call site `MOV EAX,ESI; MOV ECX,EBP; CALL 0x0080b100` (image `8b c6 8b cd e8 64 53 ff ff`); body FailMission + `FUN_005307e0` thiscall on `*(client+0xe98)`; missionId `[EAX+0x10]`; UI tail jmp `vtbl+0x448`.

- Dual A/B strengthened; function record + annotated + clean plate; chain residual item 2 closed; UF-012 sealed; matrix row; naming High. Scratch `tmp/a_0080b100.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â dual residual `aa_004f3620` VehicleEntity_SetHandbrake



- **OWN ONLY** `0x004f3620` dual residual. **No WORK_QUEUE/RESUME.**

- Sealed: live re-decompile **ÃƒÂ¢Ã¢â‚¬Â°Ã‚Â¡ raw** ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â ungated `*(u8*)(entity+0x61c)=on` (no `0xC7` vs SetSteer/Longitudinal).

- Sealed consumers: PushDriveAxes ÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢ `ctrl+0x24`; calcWheelTorque rear ÃƒÆ’Ã¢â‚¬â€0.5; hard-stop `+0x109` can force ctrl HB without reading entity HB.

- Sealed bypass: MoveToTarget **direct** `+0x61c` (not a SetHandbrake caller ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â prior record corrected); SetDriveAxes bundled store.

- Caller inventory via live xrefs (DriveControlTick, PollBoundActions, AI/UI packs). Dual A/B + function/annotated/clean + matrix. Scratch `reviews/a_004f3620.md`. **No Launcher.**





## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Skill_ResolveTargetList dual residual (`0x00550300`)



- **OWN ONLY** `aa_00550300`: link `Skill_FilterTargetForResolveList_Inferred` `0x0054ff00` + RangeCheck `0x0058c0a0`.

- **Sealed:** outFlags writers (bit1/2 this body; 4/8/0x10 Filter); invalid-TFID wipe ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â¡ `g_abTfidInvalid_A15870`; `+0x614` Self/Ally/Enemy/Minion/Ground via FormatTargetFilterTooltip; no ValidateTargetForSkill callee.

- Scratch `reviews/a_00550300.md`; clean plate helper renames; dual A/B residual notes; matrix row. **No** WORK_QUEUE/RESUME. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â PushDriveAxesToController dual residual (`0x004fbc10`)



- **OWN ONLY** `VehicleEntity_PushDriveAxesToController` `aa_004fbc10` / `0x004fbc10`: strengthen thin wave2 dual A/B.

- Sealed static residuals: thr/HB bridge gates; `DAT_00a0f734=0.9` **positive** ceiling only; speed-cap operands `local_3c < entity+0x10c`; overspeed thr-zero by **travel polarity** (not ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã¢â‚¬Å“opposingÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â); controller layout ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â  Havok VA (`ctrl+0x24` u8 HB); steer `+0x618` out-of-band.

- Three-rep: function record + annotated + clean plate comments (CF unchanged). Scratch `tmp/a_004fbc10.md`. Matrix row. **No** WORK_QUEUE/RESUME. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â CompleteMissionObjectives dual A/B spot-check (`aa_00536080`)



- **OWN ONLY** `0x00536080` dual. **No WORK_QUEUE/RESUME.**

- Live decompile ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â¡ raw; sole callers Prerequisites ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â2 (`0x005365ae` / `0x00536722`) both `uReason=1` (asm `PUSH 1`).

- Dual A/B strengthened (accept-with-gaps): bulk force objectives only; reason-forward sealed; count-0ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢1; plate ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã¢â‚¬Å“reason ÃƒÆ’Ã‚Â¢Ãƒâ€¹Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢1ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â falsified for arg4; EvaluatePending reason-0 residual dropped.

- Artifacts: `reviews/A|B_aa_00536080_*`, function record, annotated, clean plate, matrix row, scratch `tmp/a_00536080.md`. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â LocalCast residual `aa_00518c20` FUN_00518c20 leave-FUN dual



- **OWN ONLY** `0x00518c20`: lazy map shell at **`this+0x68`** (`operator_new(0xc)` + `FUN_0058d9c0` head, size `+8=0`). Twin of `Skill_GetCategoryCooldownMap` (`+0x6c`); no string/RTTI.

- **Xrefs:** 7 sites / 4 funcs ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â `Skill_LookupActiveCastBinding`, `Skill_ClearCastBindingAndMaybeRestartCd`, `FUN_00518ca0`, `Skill_LocalCastValidate` (`*(map+8)!=0` + form ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ code 10). Exclusive LocalCast **falsified**.

- Dual A/B **leave-FUN** (block `Skill_GetActiveCastBindingMap[_Inferred]`); function record + annotated + clean plate; scratch `tmp/a_00518c20.md`; skills residual close. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â CVOGReaction_CastSkillOnTarget dual residual (aa_004d09a0)



- **OWN ONLY** `0x004d09a0` dual if weak. **No WORK_QUEUE/RESUME.**

- Sealed: **no network send in unit** (callees = ResolveFromTFID / ResolveTargetList / ApplyStatusEffectLocal / heap only).

- Sealed: targets TFID base **+0x40** (mana cursor +0x50); size `n*0x18+0x58` base includes terminator; Apply `(size-0x40)/0x18` ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ n+1.

- Sealed: resolveFlags 0xd/0xe map is **local only** ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â never written to packet+0x14; status is 0/`'c'` from param_10 only; return always 0.

- Named callers: `NPC_TryCastSkillFromSet`, Outpost faction/beacon, `Skill_CVOGHBSkill_Summon`, `FUN_004d1b80` (+ bulk).

- Dual A/B strengthen; function record; annotated + clean plate; chain `reviews/CHAIN_2026-07-29_castskillontarget_0x2031_packer.md`; systems map + matrix. Scratch `tmp/a_004d09a0.md`. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â dual residual `aa_0060e0f0` CVOGObjectiveRequirement_Patrol_Eval



- **OWN ONLY** `0x0060e0f0` dual residual. **No WORK_QUEUE/RESUME.**

- Sealed: `req+0x24` = **Laps** (GetFlags image `mov eax,[esi+0x24]` ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ `<Laps>%i`); `req+0xd0` = waypoint/target count; product = needed pads; slot float = **absolute** pad count (`comiss`/`cvtsi2ss` image ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â¡ raw).

- Zero-product edge: Eval completes when `slotFloat >= 0`; Action returns `1.0`; server `NeededCount` may normalize Laps/targets (port note only).

- Dual A/B refresh; function record; clean plate; annotated; scratch `reviews/a_0060e0f0.md`; matrix row. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â FindActiveObjectiveIdForPick dual (aa_005245d0)



- **OWN ONLY** `0x005245d0`: sibling of FindActiveObjectiveIdForInteract; same `char+0x548` walk / id `@+0x10`; match via `FUN_0059da10` (**vtbl+0x44**).

- Three-rep + dual A/B; Ghidra rename `CVOGCharacter_FindActiveObjectiveIdForPick` (**Probable**); prior scaffold `ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â¦ForInteractAlt`.

- Callers (3): `Client_InteractClickPickTarget`, `FUN_00925820` (select-only), `FUN_00490070`.

- Artifacts: raw/annotated/clean/function record/reviews A|B; registry + matrix + interaction-activation; scratch `tmp/a_005245d0.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Client_RecvSkillStatusEffect opcode/FUN residual dual strengthen (aa_00811170)



- **Opcode sealed:** S2C **0x2031** ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ sole `Client_PacketDispatch` case/xref call `0x0081589c`.

- **Framing sealed:** call site `MOV EAX,ESI; MOV ECX,EBP; CALL 0x00811170` (image `8b c6 8b cd e8ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â¦`); packet in EAX, client in ECX.

- **FUN residual surface:** roles for list-lock trio, map find/erase, `FUN_0054b480` global map (ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â  GetCategoryCooldownMap), chat/log helpers; `'c'` path cross-links `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`). Remaining FUN product names open.

- Dual A/B strengthened; function record + annotated + clean plate; chain `reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md`; matrix row updated. Scratch `tmp/a_00811170.md`. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â dual residual `aa_00813730` Client_RecvInventoryDropResponse (Agent A)



- **Opcode seal Confirmed:** `Client_PacketDispatch` `case 0x2037`/`0x203b` ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ `Client_RecvInventoryDropResponse` (live Ghidra re-decompile + xref `0x008159c2`); body early-outs `0x203b` only.

- Live body re-decompile ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â¡ raw; base field plate cross-checked vs PACKET STRUCTURES + `InventoryDropResponsePacket.Write`.

- Strengthened A dual + annotated + function record + clean plate dual refs; matrix row; scratch `tmp/a_00813730.md`.

- Open: swap/concat depth, place ECX thiscall recovery, AutoCore omit of `@+0x28`/`@+0x38`, runtime. **No WORK_QUEUE/RESUME. No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â DriveControlTick camera look-offset residual



- **OWN camera only** inside `Client_Input_DriveControlTick` `0x009223b0`: dual A/B `*_camera_refresh.md` (not full re-dual); locals `local_d*` vs steer `+0x618` sealed High CF; look steps `read_memory` 0.03/0.2/5/11.

- Amended function record + `systems/input-drive-control.md` camera residual; UF-003 partial; scratch `tmp/a_camera_dct.md`. **No** WORK_QUEUE/RESUME. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â skill FUN residual renames + WQ-004 soft-steer dual refresh



- **Skills evidence-only:** `0x004f8b80` Vehicle_ResolveFirstHardpointOccupantTfid_Inferred; `0x0054ff00` Skill_FilterTargetForResolveList_Inferred (outFlags 4/8/0x10); `0x004e2600` CNDDoubleList_InvokePredicateAndRemove_Inferred; `0x005788d0` CVOGHBSkillCast_ctor_Inferred. Dual A/B each; left FUN_005169c0/00518c20 (no string).

- **WQ-004 soft-steer:** dual refresh soft/analog; UF-006 CF High / label Probable; experiments `drive_soft_steer_constants.py`.

- Durable: skills map open Q, NAMING, RESUME. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Skill_ApplyEffectsOnTarget_Inferred (`0x005538a0`)



- **Skills residual:** `FUN_005538a0` ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ `Skill_ApplyEffectsOnTarget_Inferred` (`_Inferred`; no product string). Combat/effect apply core: ResolveObjectTarget + events 4/0xc/0xe/5/6 + handler `+0x5f0` vtbl+0x2c. Callers sealed (ApplyStatusEffectLocal delay&lt;1, Recv null-source `'c'`, active-skill HB `FUN_00606180`, etc.). Dual A/B accept. Scratch `tmp/a_005538a0.md`. No WORK_QUEUE/RESUME edit.



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Collect_Action + Deliver duals + FindActiveObjectiveIdForInteract



- **Collect_Action** `aa_00611f20` / `0x00611f20`: three-rep + dual A/B; kill-loot vs inventory event; CountItemsByCbid bridge.

- **Deliver cargo readiness:** `aa_00611290` OnInventoryEvent type-4; `aa_00610f20` CargoReady predicate; both `_Inferred` names; duals.

- **Interact objective id:** `aa_00524520` FindActiveObjectiveIdForInteract (not bool); helper `aa_0059d9c0` MatchTargetEvaluators; duals.

- Experiments structural tests extended; suite re-run OK. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Inventory collect bridge + interaction + modal pairing + skills ValidateTarget



- **InventoryÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã‚Âcollect:** `InventoryGrid_CountItemsByCbid` `0x005711c0` + `CVOGObjectiveRequirement_Collect_Eval` `0x00611940` (cargo `char+0x250ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢+0x2b0`); chain `CHAIN_2026-07-29_inventory_collect.md`; duals A/B; experiments `inventory_collect_bridge.py`.

- **WQ-006 interaction:** system map `interaction-activation.md`; UseObject `0x2072` duals; IfInteractable objective-id find (not bool); SYS-INTERACT active/partial.

- **UF-009 modal pairing High:** `Client_ShowModalPrompt` `0x007fdfb0` ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â abandon open loads **EAX=0x4e46** (Yes) + stack **0x4e47** (No); asm at HandleButton call site.

- **Skills:** `Skill_ValidateTargetForSkill` asm ABI sealed (wrapper AL polarity inverted vs handler 1=reject); evidence renames HBSkillListener, Outpost cast helpers.

- **Missions:** CheckMissionPrerequisites dual refresh (mutator not pure check).

- **Inventory grab/drop:** dual A/B quality refresh; opcodes 0x2034/0x2036 Confirmed.

- Durable: WORK_QUEUE WQ-006..009, SYSTEM_INDEX, NAMING, RESUME. Experiments suite OK. **No Launcher.**



## 2026-07-29 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Seal C2S 0x206E + abandonÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢FailMission (static)



- **0x206E send site sealed:** `Client_NpcDialog_PrepareResponseOpcode` (`0x008abd70`) sets `dialog+0x650=0x206E`; `Client_MissionDialogHandleButton` state 1 fills payload only; **`Client_MissionDialog_FlushPreparedResponse`** (`aa_008ab8f0` / `0x008ab8f0`, was `FUN_008ab8f0`) sends size **0x20** from `+0x650` via `DAT_00d1b4b8` vtbl+0x18 (asm + vtable DATA `0x00a4a95c`). Chain: `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`.

- **AbandonÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢FailMission sealed (static):** HandleButton state 2 stashes `DAT_00d1b4b4`, modal `0x4e47`; `FUN_00911840` case **`0x4e46`** sends C2S **`0x20B2`** size **0x18**; `CVOGReaction_FailMission` apply + dual refresh; `Client_RecvFailMission` (`aa_0080b100`) duals. Chain: `reviews/CHAIN_2026-07-29_abandon_failmission.md`. Residual: modal Yes/No pairing Probable; runtime open.

- Artifacts: `reconstructed-exact/Client_MissionDialog_FlushPreparedResponse.cpp`, `Client_UiModalDispatch_AbandonConfirm.cpp`; experiments `mission_dialog_c2s.py` + tests (**17** new; full suite **44 OK**).

- Updated: NAMING_REGISTRY, VERIFICATION_MATRIX, systems/missions-progression, WORK_QUEUE WQ-007, RESUME, function records, dual A/B for flush/abandon/FailMission. **No Launcher.**



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Skeptic gap fix: matrix + WORK_QUEUE dual sync



- `VERIFICATION_MATRIX.md`: Ind.rev/Skep.rev=Y + Last reviewed 2026-07-28 for GiveMission, CheckMissionRequirements, SetLongitudinalInput, RecvSkillStatusEffect, DriveControlTick, NPC_TryCastSkillFromSet; removed false ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã¢â‚¬Å“map-only / no function recordÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â claim for `aa_009223b0`.

- `WORK_QUEUE.md` WQ-003: dual A/B present (accept-with-gaps); residual runtime/diff only. WQ-004: unit + dual present (not queued raw capture).



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â NPC_TryCastSkillFromSet human refine + dual status sync



- **Address `0x005d1280` / `aa_005d1280`:** dual A/B already present (accept-with-gaps); clean comments refined (9-stage plate + open links); function record + skills-abilities unit status updated from scaffold.

- Open gaps left on system map: seal `NPCSkillSetEntry` (0x18), cast-result return type, server-only `world+0x7e`, live AI cast capture, threat scalar.

- Artifacts: `reconstructed-exact/NPC_TryCastSkillFromSet.cpp`, `functions/aa_005d1280_NPC_TryCastSkillFromSet.md`, `reviews/A|B_aa_005d1280_NPC_TryCastSkillFromSet.md`. **No Launcher.**



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Client_RecvSkillStatusEffect refine (aa_00811170)



- **Clean plate:** removed non-authoritative empty stub; single full decomp body retained (behavior-preserving). Strengthened plate comments: packet layout (0x9a0 / 0x2031), status gate `{0,'c',0x11}`, local-caster TFID match, unresolved FUN_* list.

- **Dual A/B:** strengthened confidence tables + open questions (opcode seal, `'c'` semantics, FUN_* residual surface). Verdict remains **accept-with-gaps**.

- **Function record / annotated / skills system map:** status ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ human-refined + dual review.

- **No Launcher.** Paths: `reconstructed-exact/Client_RecvSkillStatusEffect.cpp`, `reviews/A_aa_00811170_*`, `reviews/B_aa_00811170_*`, `functions/aa_00811170_*`.



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â `aa_005462b0` CheckMissionRequirements dual A/B strengthen

- Strengthened dual reviews for `CVOGCharacter_CheckMissionRequirements` (`0x005462b0`): body-backed mission-def offsets (+0x90 race, +0x92 faction, +0x94/+0x98 level, +0x104/+0x108 currency, +0x118 flag, +0x9c prereqs; +0x120/+0x124 mode CF); pure eligibility gate (no side effects); dual status accept-with-gaps.



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â inv-place inventoryType/grid offsets (`aa_00571620`)



- Confirmed **three representations** + **dual A/B** already present for

  `InventoryGrid_PlaceItemFootprint` (`aa_00571620` / `0x00571620`): raw,

  annotated, clean `InventoryGrid_PlaceItemFootprint.cpp`, A/B reviews

  (`accept-with-gaps`).

- Documented **raw-only** offsets: DropResponse `inventoryType` @ packet

  **`+0x1a`** (cases 1/3/5/6 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ grid `+0x2b0` / `+0xcbc` / `+0xce0` / TFID+`0xce0`);

  place X/Y `@+0x18/+0x19`; InventoryGrid `+0x04/+0x08/+0x0c/+0x10/+0x14/+0x18/+0x1c/+0x24/+0x28`

  (cells 8 B, empty `0xFFFFFFFF`); clonebase InvSize `+0x406/+0x407`.

- Place unit does **not** read inventoryType (caller resolves grid). Stamp loop

  formula still unsealed (`unaff_SI` / `bStack_8`).

- Updated: function record, `systems/inventory-transfer.md`, `OBJECT_LAYOUTS.md`,

  VERIFICATION_MATRIX row. **No Launcher.**



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â CVOGReaction_GiveMission dual A/B spot-check (`aa_005327c0`)

- Confirmed three layers: raw/annotated `raw/aa_005327c0_*`, clean `reconstructed-exact/CVOGReaction_GiveMission.cpp`, function record `functions/aa_005327c0_*`. Refreshed dual reviews `A_aa_005327c0_*` / `B_aa_005327c0_*` (purpose, High/Probable/Tentative, open questions, CF cleanÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â¡raw). CF fix: outer already-active (`+0x540` hit) returns **0** (not 1); inner ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã¢â‚¬Å“Already had missionÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â returns **1**. Param renames evidence-only. Verdict: **accept-with-gaps** (client CF High). No Launcher.



## 2026-07-28 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â SetLongitudinalInput `aa_004f5650` dual confirm

- Confirmed three representations (raw/annotated/clean) + dual A_/B_ for `VehicleEntity_SetLongitudinalInput` @ `0x004f5650` (gate **0xC7**, store **+0x614**, wobj-null allow); sign convention cross-check vs `systems/input-drive-control.md` (**Accelerate = ÃƒÆ’Ã‚Â¢Ãƒâ€¹Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢1** caller-owned; CF unchanged). Dual status: **present**, verdict **accept-with-gaps**. No Launcher.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Experience_*/Tech/Serialize/DB dual A/B (34 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for remaining

  `Experience_*` helpers, `Character_GetTechForPoolCalcs`, both

  `CreateSimpleObject_Serialize*`, `DB_ReadPowerPlantSpecific`, plus **24** other

  high-value named managers still missing duals (cap priority + 25 others;

  never Launcher):

  - **Experience:** `GetCreatureXpForLevel` (missÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢0), `GetCumulativeThreshold`

    (missÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢0x7FFFFFFF), `XpToReachRelativeLevel` (+0xc54 / +0x730 formula),

    three `Ensure*TableLoaded_INFERRED` twins

  - **Tech / serialize / DB:** Tech clamp **[1,250]** with pre-cap 200;

    CreateSimpleObject **0x2012/0xD8** primary vs Variant2 this-base split;

    power-plant **0xC** row ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ clonebase **+0xB0..+0xBA**

  - **XP-adjacent fill:** Outpost pulse XP + percent tables, StdMap lower_bound,

    `Mission_tExperienceLevel` / `tQuestXPLookup` / `tCreatureExperienceLevel` /

    `tContinentExploredAreas` loaders

  - **Loot / item / vehicle:** `Inv_tLoot*` / generate id+type / credits / pickup /

    `tItemTemplate` / `vLootBaseItems`, `Drive_tVehicleTemplate`, loot prefix map,

    heat-mult map (ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â  ApplyShotHeat), map erase, creature graphics, sector map save

- Notable skeptical hits: never conflate creature-XP miss 0 with cumulative

  sentinel 0x7FFFFFFF; Serialize vs Variant2 this-bases differ; Ensure bodies do

  not show ready-flag writes; rlWeaponHeatMultiplier is table ops not fire cost.

- Report: `docs/agents/task-dual-ab-exp-tech-serialize-db-report.md`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Net_*/CLoad*/Phy_*/hkDefault*/Weapon_* dual A/B (30 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for remaining high-value

  named managers missing both A_/B_ pairs (cap 30; prefer Net/CLoad/Phy; never Launcher):

  - **Net/Ghost:** `UnpackGhostUpdate` (+ sibling `005b17b0`), `PackInitialCharacterUpdate`,

    `GhostConnection`, `getUpdatePriority`, `NetObject_SetMaskBits` (OR + dirty list),

    `GhostObject_OnGhostAdd`, `InitNetworking_sector`

  - **CLoad:** full `CLoadQueue_Update` + `CLoadNode` stage pipeline (`initPreload` /

    `initAnim` / `initPhysics` / `initFull` / `initAI` / post-create / selection / barriers)

  - **Phy/CPhysX:** `CollectAllPhysicsPreloads`, `Start_ReinitPhysics`, `Inside_InitPhysics`,

    `Preload_ReloadRigidBody`, `BoundingVolumeFactory_CreateFromTag`, `CPhysXBase_Step` /

    `RenderResults`

  - **Drive companions:** `hkDefaultAnalogDriverInput_calcReverse` / `calcStatus`,

    `hkDefaultBrake_update` (WI-MOV-005)

  - **Weapon heat:** `CanFireHeatCheck` (heat +0x150 vs max +0x244), `ApplyShotHeatAndPowerCost` (type 0xE)

- Notable skeptical hits: ghost unpack VAs must stay split from VehicleNet; SetMaskBits is OR

  not replace; initAI vtbl+0xc0 attaches HBAI while recalculate only sets +0x64; CPhysX Step is

  one-shot ~1/30; weapon costs gate on owner type 0xE.

- Report: `docs/agents/task-dual-ab-net-cload-phy-report.md`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Vehicle thin + Skill_Uses_* dual A/B (25 units)



- **New modern dual reviews** for remaining thin **Vehicle_*** / **VehicleEntity_***

  combat-pool and drive-axis units, all **Skill_Uses_*** string aliases, and related

  fills (cap 25):

  - **Regen getters:** `GetHpRegenRate` (+0x3FA), `GetShieldRegenRate` (+0x4B6),

    `GetPowerRegenRate` (plant+0xB8 / default 1), `GetCoolRate` (plant+adjust)

  - **Combat/drive thin:** `IsAnyWeaponFiring` (turret+3 HP, flag +0xC7),

    `SetHandbrake` (ungated +0x61c), `SetFlag_109` (+0x109 meaning open),

    `Creature_GetHpRegenFromEquippedRaceItem` (creature+0x250 glue)

  - **Skill ledger:** real `SkillSet_GetEntryCount` (stride 0x18) + 9 `Skill_Uses_*`

    aliases (explicitly **not** product drop-ins for EnsureLoaded / ResolveTargets)

  - **Physics/net fill:** `torqueCurve2D`, `calcWheelTorque`, `tickSubsystems`

    (framework this), `VehicleAction_ctor`, airStabilization, TriggerReplay,

    ReconcilePrediction

- Notable skeptical hits: Skill_Uses VAs ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â  thin/real namesakes; tickSubsystems

  `this` is hkVehicleFramework; SetHandbrake has no 0xC7 gate.

- Report: `docs/agents/task-dual-ab-vehicle-thin-skill-uses-report.md`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Plate-driven domain FUN_* aliases full address range (200 units)



- **200 domain-named clean aliases** for remaining `FUN_*` units across full VA range with

  PURPOSE/READABILITY embedded-string evidence (skipped if non-CalleeOf alias already present).

- Domains: `CVOG*` loot/graphics/AI/waypoint, `CLoadNode_*` init pipeline, `Inv_*` loot/item tables/UI,

  `Mission_*` quest UI/position, `Combat_*` weapon/target/damage, `Phy_*` / `Gfx_*` FX, `Net_*` ghost,

  `Skill_*` phantom cast / sc UI, `Drive_*` speed particles, `UI_*` chrome, data-cursor `Named_dc*`.

- `FUN_*.cpp` originals retained; function records got `## Alias` human names where present.

- **Not** `Named_CalleeOf_*`. Report:

  `docs/reconstruction/coverage/plate_domain_rename_full_range_report.txt`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Plate-driven domain FUN_* aliases [0x00600000, 0x00a00000) (100 units)



- **100 domain-named clean aliases** for `FUN_*` units at VA in `[0x00600000, 0x00a00000)` with

  PURPOSE/READABILITY embedded-string evidence (skipped if non-CalleeOf alias already present).

- Domains: `CVOG*` trigger/screen, `Phy_*` init/reinit physics, `Net_Nazgul_*` / ghost pack-unpack,

  `LCD_*` Logitech LCD, `Snd_*` streaming music, `Inv_*` loot tables/UI, `Mission_*` XP/quest tables,

  `Drive_*` vehicle/wheel templates, `Combat_*` weapons/respawn, `UI_*` arena/mail/clan/chat,

  `Gfx_*` NDAsset/FX, `CNDAssetStringTable_*`, data-cursor `Named_dc*`.

- `FUN_*.cpp` originals retained; function records got `## Alias` human names where present.

- **Not** `Named_CalleeOf_*`. Report:

  `docs/reconstruction/coverage/plate_domain_rename_6m_a0_report.txt`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Plate-driven domain FUN_* aliases under 0x00500000 (50 units)



- **50 domain-named clean aliases** for `FUN_*` units at VA `< 0x00500000` with

  PURPOSE/READABILITY embedded-string evidence (skipped if non-CalleeOf alias already present).

- Domains: `CVOG*` sector/map step paths, `CPhysXBase_*` / `Phy_*`, `Gfx_*` (FX/PNG/BMP/particles),

  `Net_Nazgul_*`, `Sto_*`, `Snd_*`/`Anim_*` preloads, `Util_HashList*`, `Zlib_*`, `Skill_NonCreatureCastAutoHit`.

- `FUN_*.cpp` originals retained; function records got `## Alias` human names.

- **Not** `Named_CalleeOf_*`. Report:

  `docs/reconstruction/coverage/plate_domain_rename_under_500k_report.txt`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Mission_*/Skill_*/Inv_*/Drive_* dual A/B (30 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for highest-value

  `Mission_*` / `Skill_*` / `Inv_*` / `Drive_*` clean units missing both A_/B_ pairs (cap 30):

  - **Mission:** `ComputeObjectiveCredits`, `ClaimSelectedReward` (C2S 0x20c6 seed),

    `HandleEndQuest`, `BuildMissionDetailPanel`, `BuildMissionXmlPath`, `StreamMissionStrings`

  - **Skill cast stack:** `LocalCastValidate`, `LocalRangeTargetCheck`, `ValidateTargetForSkill`,

    `ResolveTargetList`, `GatherTargetsInArea` (TFID stride 0x10), cast bookkeeping

    (`SetIsCastingFlag`, `Lookup/Clear` bind, `QueueDeferredCastId`, `StartCastAgainHeartbeat`),

    rank/runtime (`EvaluateRankedElements`, `CopyRuntimeFieldsFromTemplate`, `EnsureLoadedInTree`),

    `ApplyStatusEffectLocal` (0x2031), summon HB, tooltip formatter

  - **Inv:** equip clonebase slot validate, craft affordability, post-random integrity, RE client path

  - **Drive:** `MoveToTarget3DPoint` (thr/steer/HB axes), water FX, vehicle collision listener

- Notable skeptical hits: credits formula is delta-only (no +0x720 write); claim opcode payload open;

  MoveToTarget UF-007 gate residual; LocalCastValidate is client precheck not server authority.

- Report: `docs/agents/task-dual-ab-mission-skill-inv-drive-report.md`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Auth*/AuthClient_*/BitStream_* dual A/B remaining (8 units)



- **New modern dual reviews** for the **8** unique VAs still missing both A_/B_ under

  Auth* / AuthClient_* / BitStream_* clean filters (cap 40; AuthClient_* + BitStream_* already complete):

  - **Trace:** `authMessageTrace` receive `0x00727b70`, send `0x00727c00`

  - **Login UX:** `FormatUnknownAccountChatLine`, `RequireAccountName`,

    `i_d_fesh_*` shard select, `i_d_fet_*` account entry (+ password XML)

  - **Auth state:** `No_authentication_key` `0x009332b0`, `Setup_of_CNDAuthClient_failed` `0x008223e0` (init + fail branch)

- Notable skeptical hits: fesh ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â  fet screens; Setup_* is constructor not fail-only;

  authMessageTrace is log-only; `0x6900` arg on missing-key path unsealed.

- Post-batch: **0** Auth*/AuthClient_*/BitStream_* clean units missing duals.

  Report: `docs/agents/task-dual-ab-auth-bitstream-report.md`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Client_*/CVOG* dual A/B wave 3 (20 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for remaining clean

  `Client_*` / `CVOG*` managers that lacked both A_/B_ pairs (cap 20):

  - **CVOG:** `SectorMap_LoadMapFile`, `Variable_EvaluateComputed`, `Physics_ApplyImpulseVector`,

    `PlayerVehicle_UpdateTurretAiming`, `Vehicle_GetWeaponSlotTransform`, `Reaction_BuildTextParams`,

    `Reaction_RandomUnitScalar` (RNG singleton misnomer), `RoadNode_ParseWidthFromTexName`

  - **Input:** `ActionMap_Init`, `InitActionDisplayNames`, `Input_OnKeyDown_MatchAction`,

    `Input_PollBoundActions`

  - **Mission/UI:** `UpdateObjectiveDisplayHud`, `RefreshOpenMissionUiWindows`,

    `NotifyActiveMissionChanged`, `HideMissionDialogIfOpen`, `ShowMissionRewardChatToast`

  - **Tips / skills:** `MaybeShowFirstTimeTip`, `SetFirstTimeTipBit`, `QuickBarActivateSkillSlot` (C2S 0x2030)

- Notable skeptical hits: RandomUnitScalar is not a float; map var types 0xB/0xC use active hashes;

  reward toast is display-only (+0x538); QB skill path is 0x28-byte 0x2030.

- Post-batch: **43** Client_* still dual-missing; **no CVOG*** left without duals in filter.

  Report: `docs/agents/task-dual-ab-client-cvog-wave3-report.md`. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â CVOGObjectiveRequirement_* dual A/B wave (14 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for all clean

  `CVOGObjectiveRequirement_*` units that lacked A_/B_ pairs (14/14, under 30-pair cap):

  - **Kill:** `Eval` `0x00613910`, `Precheck` `0x00613b50`

  - **Patrol:** `Eval` `0x0060e0f0`, `Action` `0x0060e120`, `GetFlags` `0x0060e260`,

    `GetTarget` `0x0060e370`, `InitActive` `0x0060e3d0`, `GetSomething` `0x0060e9e0`

  - **UseItem:** `Eval` `0x0060cfe0`, `InitActive` `0x0060d540`, `MatchTarget` `0x0060d7f0`,

    `OnComplete` `0x0060cfd0`, `SerializeXml` `0x0060d800`, `SlotAction` `0x0060d060`

- Notable skeptical hits: eval family is pure compare (not mutators); UseItem required count is

  `+0x50` (not KillÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢s `+0x18`); Patrol_GetFlags is XML dump not bitflags; MatchTarget is trampoline

  to `FUN_0060d460`; OnComplete is empty ret; Kill_Precheck has unaff_EBP / param_3 alias gaps.

- Function records linked to duals; `systems/missions-progression.md` dual table extended.

  Runtime/diff/bit-exact still open. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Low-priority systems readable plates (physics / networking / lighting)



- Human-refined clean plates (Purpose / CF summary / key offsets / dual-review links) for **20** existing units:

  - **BitStream_***: `writeBits`, `readBits`, `writeFlag`, `readFlag`, `writeInt`, `readInt`, `writeQuantizedFloat`

  - **Client_SendSectorPacket** `0x00807460`, **Client_RecvBroadcast** `0x00810a80`

  - **CVOGPhysics_ApplyImpulseVector** `0x0040d260`

  - **gfx***: `GeometryPiece` Serialize/Unserialize, `IndexBufferImpl` S/U, `VertexBufferImpl` S/U

  - **phy***: `phyBone_unserialize`, `phyBoneSharedData_unserialize`, `Phy_BoundingVolumeFactory_CreateFromTag`

  - **Named_gfxLightManager** shutdown path `0x0074e3e0`

- Ghidra plate comments set/updated for BitStream family, sector send/recv, CVOGPhysics, gfxLightManager.

- Dual reviews for `BitStream_writeBits` and `Client_SendSectorPacket` **already present** (A_/B_ accept-with-gaps) ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â not recreated.

- Function records system tags + purpose lines updated. Runtime/diff/bit-exact still open. **No Launcher.**



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Mission progression dual A/B wave (9 units)



- **New modern dual reviews** (A reconstruction + B skeptical) for units that lacked A_/B_ pairs:

  `HasCompletedMission` `0x0052aa20`, `CompleteMissionObjectives` `0x00536080`,

  `EvaluatePendingObjectives` `0x00534920`, `SearchAutoMissions` `0x00532b60`,

  `AddCredits` `0x005355a0`, `AddSkillPoints` `0x005312c0`, `AddAttributePoints` `0x00531250`,

  `AddActiveObjective` `0x00531b00` (upgraded from prior reconstruction/skeptical),

  `EvalActiveObjectiveInteractState` `0x004d3ef0`.

- Notable skeptical hits: skill/attrib ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã¢â‚¬Å“Add*ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â are **assign** not `+=`; HasCompleted is not naÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¯ve hash OR;

  SearchAuto skips via manual +0x538 walk (not HasCompletedMission API); CompleteMissionObjectives

  forwards `uReason` (not fixed ÃƒÆ’Ã‚Â¢Ãƒâ€¹Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢1 on 4th arg).

- Matrix Ind.rev/Skep.rev set Y for the five matrix-listed mission units; dual table in

  `systems/missions-progression.md` updated. Runtime/diff/bit-exact still open. No Launcher.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â AI managers human-readability (HBAI / HB / spawn / map-path)



- Human-refined clean plates (Purpose / CF summary / key offsets / callees) for AI managers already named under `reconstructed-exact`:

  `CVOGHBAI*` (factory, base, creature, driver, follow, find-target, aggro, ctors),

  `CVOGHB*` (base list/try-fire/reschedule, regeneration, OKToCastAgain, mission-patrol),

  `CVOGSpawn*`, `CVOGMapPath_AdvanceAndSteer`, `AI_CheckSlotTimerReady`.

- System tags normalized to `npc-ai / HBAI`, `heartbeat / timed-actions`, `heartbeat / combat-pool`, `npc-ai / spawn`, `npc-ai / map-path` as appropriate.

- **New dual reviews** (were missing): `A_/B_aa_005d0310_CVOGHBAICreatureBase_OnHeartBeat`, `A_/B_aa_00639210_CVOGHBAIBase_FindTargetToAttack` (accept-with-gaps / needs-more-evidence on helpers).

- Behavior preserved; runtime/diff/bit-exact still open. No Launcher / no disassemble_bytes.



## 2026-07-23 - input-drive-control human-readability (keybind + input clean)



- Human-refined cleans: Client_ActionMap_Init, Client_InitDefaultKeybinds, Client_InitActionDisplayNames (force_decompile recovery of failed raw), Client_Input_OnKeyDown_MatchAction, Client_Input_PollBoundActions (stripped corrupt prefix), Drive_CVOGVehicle_MoveToTarget3DPoint (+ _004fc650 twin).

- Param renames where clear: ActionMap object pActionMap (ESI/EDI/EAX register pass); OnKeyDown pClient.

- Section banners: keybind DIK groups (Inventory / QB / Shift-QB / helpers); display-name drive axes (Accelerate/Reverse/Steer/Soft/Brake); OnKeyDown ESC vs table scan.

- Dual reviews new for keybind init: A_/B_aa_007f8720_Client_InitDefaultKeybinds (accept-with-gaps / needs-more-evidence). Main tick dual reviews already present (A_/B_aa_009223b0).

- Raw append for aa_007f7570 force_decompile recovery. Function records updated for keybind/init/display/OnKeyDown units.

- Drive thr/steer DIK defaults not sealed in InitDefaultKeybinds body (helpers open). Setter cleans (SetSteer/Long/HB/Push/SetDriveAxes) already refined - left intact.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Mission dialog / journal / objective chain readability



- Human-refined clean plates + inline comments for dialog/journal/objective hubs:

  `Client_ShowNpcMissionDialogUI`, `Client_UpdateMissionJournal`,

  `Client_FindObjectiveMatchingTarget`, `CVOGObjectiveRequirement_{UseItem,Patrol,Kill}_Eval`,

  `Patrol_GetTarget`, `UseItem_MatchTarget`.

- Already-refined hubs linked to new duals: `RecvNpcMissionDialog`, `MissionDialogHandleButton`,

  `RecvObjectiveState`, `AddActiveObjective` (prior duals).

- **New dual reviews (A reconstruction + B skeptical):**

  `RecvObjectiveState` `0x00809460`, `MissionDialogHandleButton` `0x008ae7c0`,

  `RecvNpcMissionDialog` `0x00815070`, `UpdateMissionJournal` `0x008ae130`,

  `ShowNpcMissionDialogUI` `0x009438f0`, `FindObjectiveMatchingTarget` `0x00525bd0`.

- Matrix + `systems/missions-progression.md` entry points / dual table updated.

- Behavior preserved; runtime/diff/bit-exact still open. No Launcher / no disassemble_bytes.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Inventory + skills human-readability wave



- Human-refined clean plates (Purpose / CF summary / key offsets / dual-review links) for inventory + skills Client_* / SetQuickBar units.

- Full refine (names + CF): `Client_Skill_ResolveCastTarget` `0x0093b3a0`, `Client_QuickBar_ActivateSlot` `0x009436c0`, `CVOGCharacter_SetQuickBarSkill` / `SetQuickBarItem`.

- Plate upgrades (behavior-preserving): Recv Grab/Drop/Add/Unequip/Use*, Send Grab/Drop/Add/Unequip*, UI DropToGrid / ItemClickDispatch, QuickBarActivateSkillSlot.

- Param renames where roles clear only: ItemClickDispatch `param_1`ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢`pWidget`; SendInventoryAddItem `param3`ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢`mergeContext`; ActivateSlot/ResolveCastTarget formals named.

- **New dual reviews:** `A_/B_aa_0093b3a0_Client_Skill_ResolveCastTarget`, `A_/B_aa_009436c0_Client_QuickBar_ActivateSlot`. Prior aa_* duals already on Grab/Drop/DropToGrid/RequestCast/CastFromQB/QBActivateSkillSlot.

- Behavior preserved; runtime/diff/bit-exact still open.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Manager readability pass (missions / skills / inventory / drive)



- Refined plates + control-flow summaries on manager units: `Client_PacketDispatch`, `Client_AwardKillExperience`, `CVOGCombat_CalculateAndAwardKillXP`, `CVOGReaction_CompleteObjective`, `Client_RecvInventoryEquip`, `Client_RequestCastSkill`, `Client_CastSkillFromQuickBarSlot`, `Client_Input_DriveControlTick`.

- Param renames only where roles clear: PacketDispatch `pCtx`/`pPacket`/`pPayload`; DriveControlTick `pClient`/`pVehicle`. Behavior preserved.

- New A_/B_ dual reviews (with confidence tables) for PacketDispatch, CompleteObjective, RecvInventoryEquip, RequestCastSkill, CastSkillFromQuickBarSlot. Prior A/B kept for AwardKillExperience, CalculateAndAwardKillXP, DriveControlTick.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Skill cast chain refine + dual reviews



- Cast chain: `LocalCastValidate` `0x0051a790`, `ResolveTargetList` `0x00550300`, `ApplyStatusEffectLocal` `0x0051aa00`, `StartCastAgainHeartbeat` `0x00519200`, `CVOGHBOKToCastAgain_ctor` `0x0051e240`, plus notes for `RecvSkillStatusEffect` / `NPC_TryCastSkillFromSet`.

- Human-refined annotated + clean + function records for ResolveTargetList, ApplyStatusEffectLocal, StartCastAgain, ctor; LocalCastValidate already refined.

- **Dual reviews (reconstruction accept-with-gaps + skeptical needs-more-evidence):** LocalCastValidate (prior), ResolveTargetList (new), ApplyStatusEffectLocal (new).

- Ghidra callers: ResolveTargetList also used by `Client_Skill_ResolveCastTarget` `0x0093b3a0` (player path); Apply by Recv + CastSkillOnTarget.

- Matrix rows + NAMING_REGISTRY + `systems/skills-abilities.md` flow updated. Runtime/diff still open.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â CompleteObjective vertical (human-refine + dual reviews)



- Finished CompleteObjective vertical five units: `CVOGReaction_CompleteObjective` `0x00533f90`, `Mission_ComputeObjectiveXp` `0x0059dde0`, `Mission_ComputeObjectiveCredits` `0x0059df20`, `Client_RecvCompleteDynamicObjective` `0x0080ff00`, `Client_RecvObjectiveState` `0x00809460`.

- Human-refined clean C++ for all five (Xp/Credits/RecvCompleteDynamic from scaffold; CompleteObjective + RecvObjectiveState already refined ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â caller note fix on CompleteObjective).

- Dual reviews: CompleteObjective (pre-existing accept-with-gaps / needs-more-evidence); ComputeObjectiveXp (new reconstruction + skeptical).

- Upgraded annotated layers for Xp / Credits / RecvCompleteDynamic; function records to human-refined status.

- Verification matrix rows added/updated for the five; runtime/diff/bit-exact remain open.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Full-coverage goal wave (managers)



- Replanned toward full-coverage goal without claiming completion: **~36** durable units vs **~26256** Ghidra functions.

- WORK_QUEUE: kept WQ-001..006 + WQ-PHY; marked **WQ-003** SetLongitudinalInput **partial** (raw/annotated/clean/record exist; reviews/runtime open).

- Added high-priority manager items: **WQ-007** missions (96), **WQ-008** inventory (94), **WQ-009** skills (93).

- Physics **WQ-PHY** remains **deferred**.

- ACTIVE_WORK ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ multi-system wave (missions + inventory + skills) with exact dual-review next steps.

- RESUME / PROJECT_STATE updated for wave focus and incomplete-coverage snapshot.



## 2026-07-23 ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â Bootstrap + input-drive-control unit



- Created required durable state files under `docs/reconstruction/`.

- Ensured directories: `architecture/`, `systems/`, `functions/`, `types/`, `evidence/`, `experiments/`, `reviews/`, `raw/`, `reconstructed-exact/`, `modernized-reference/`.

- Indexed prior physics and inventory/motion RE without erasure.

- Selected system `input-drive-control`; unit `aa_004f5620`.

- Added raw/annotated/clean/function artifacts for SetSteerInput (see those paths).

- Added system map `systems/input-drive-control.md`.

- Added pure-gate experiment + tests under `experiments/`.

- Verification matrix: runtime/diff open; unit status partial after independent reviews.

- Reviews: reconstruction accept-with-gaps; skeptical needs-more-evidence on lock naming / soft polarity / full pythonÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â°Ãƒâ€šÃ‚Â¡retail.

- Post-review: rename lockÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢suppress; document intermediate-null fault; UF-006..008.



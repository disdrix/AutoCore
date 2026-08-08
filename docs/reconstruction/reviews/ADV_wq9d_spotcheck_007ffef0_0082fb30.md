# Independent adversarial spot-check — WQ9D-I dual `0x007ffef0` + `0x0082fb30`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ9D-I dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ9D-I OWN pair (WQ-009 depth residual consumers) |
| **Units** | `0x007ffef0` `Client_CombatChat_EmitEventLine_Inferred`; `0x0082fb30` `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` |
| **Tools** | Dual report + A/B + clean/raw/function-record/scratch read-through; frozen raw decompile bodies; dual live-reverify byte plates |
| **Live Ghidra this session** | **Unavailable** — agent tool host has no MCP call surface; HTTP `127.0.0.1:8089` blocked (SSRF). Dual’s 2026-08-04 live re-verify (`decompile`/`read_memory`/callers) used as sealed secondary evidence only after independent CF audit of frozen raw. |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no runtime Confirmed) |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-007ffef0-0082fb30-wq9di-report.md` |
| `docs/reconstruction/reviews/A_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |

### Artifacts (both units)

| Kind | `aa_007ffef0` | `aa_0082fb30` |
|---|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.md` | `docs/reconstruction/raw/aa_0082fb30_FUN_0082fb30.md` |
| Annotated | `…/aa_007ffef0_FUN_007ffef0.annotated.md` | `…/aa_0082fb30_FUN_0082fb30.annotated.md` |
| Clean named | `…/Client_CombatChat_EmitEventLine_Inferred.cpp` | `…/UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.cpp` |
| Clean twin | `…/FUN_007ffef0.cpp` | `…/FUN_0082fb30.cpp` |
| Function named | `…/aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` | `…/aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| Function scaffold | `…/aa_007ffef0_FUN_007ffef0.md` | `…/aa_0082fb30_FUN_0082fb30.md` |
| Scratch | `…/tmp/a_007ffef0_wq9di_notes.md` | `…/tmp/a_0082fb30_wq9di_notes.md` |

### Independent verification basis (this session)

| Check | Result |
|---|---|
| Body size math | `0x00800ad1−0x007ffef0` = **`0xBE1` (3041)**; `0x0082fc31−0x0082fb30` = **`0x101` (257)** — matches dual/function records |
| Frozen raw CF (007ffef0) | Full gate → resolve → relevance → name climb → type switch → `FUN_008f8200` walk audited end-to-end |
| Frozen raw CF (0082fb30) | Full gate → Invite/Kick exclusive → create/label/store/disable walk audited |
| Dual live-reverify bytes (scratch + raw append) | Entry `8B 44 24 04` / epilogue `C2 08 00` (007ffef0); entry `83 BA B4 06 00 00 01` / epilogue `5F C3` (0082fb30) |
| Channel immediates in raw switch | `0x10`/`0x11`/`0x12`/`0x13`/`0x14`/`0x15`/`0x16` present exactly where dual claims |
| String/ID plates in raw | `"for"`/`"Hits"`/`"Saps"`/`"XP"`/`"(Shielded)"`/`"Invite To Convoy"`/`"Kick From Convoy"`/`i_m_int_2d_btn_generic.xml`/`0x11171`/`0x11172` |
| Clean named role/ABI/channel/slot map vs raw | Role + sealed constants match; clean 007ffef0 intentionally abbreviated (documented) |
| A/B/report verdict alignment | All three surfaces: **accept-with-gaps** both units; Terminal **false** |
| Live Ghidra this session | **Not executed** (tool surface) — no independent byte re-read beyond dual-published plates |

---

## Unit A — `0x007ffef0` Client_CombatChat_EmitEventLine_Inferred

### Body / ABI / role seal (independent)

| Claim | Independent result |
|---|---|
| Range half-open `0x007ffef0`–`0x00800ad1` (**3041 B** / `0xBE1`) | **Confirmed** — size math + dual meta |
| Two stack args; **`ret 8`** (`C2 08 00`) | **Confirmed** — dual re-verify epilogue @ `0x00800acd`; raw signature two formals |
| **Not** `__thiscall` | **Confirmed** — entry plate `mov eax,[esp+4]` then `+0xF40`; ECX unused at entry |
| Role = combat **chat format + sink** (not damage/cast sim) | **Confirmed** — sole terminal sink `FUN_008f8200`; no packet send; plates are English combat lines |
| Gates: host `+0xF40`, `DAT_00d1b644`, `event!=null` | **Confirmed** — raw early returns |
| Self-dodge suppress: target==source TFID, equals local COID climb, `param_2[2].bPad1` | **Confirmed** — raw lines 68–73; returns |
| Resolve target=`param_2+1`, source=`param_2+0` | **Confirmed** |
| Local vehicle tests via `vtbl+0x210` vs host `+0xE98` | **Confirmed** — `bVar1`/`bVar2` |
| Related path: `vtbl+0x1D8` → `FUN_0040aff0` × uses → null TFID `DAT_00a1e850` → crew `FUN_005749d0` + `DAT_00af921c` bits | **Confirmed** — raw LAB tree |
| Spam suppress: if !local/!related require `localVeh+0xCB0` + crew on target or source | **Confirmed** |
| Require non-empty target name buffer | **Confirmed** — `local_140[0]==0` → return |
| Type switch `param_2[3].dwCoidLo` 0..3 | **Confirmed** |
| Case 0 flags: dodge/`bPad1`, resist/`bPad2`, deflect/`bPad3`, crit/`bPad0` → channel **0x12** family / **0x10** crit / **0x11** dmg / **0x16** shielded | **Confirmed** — raw switch body |
| Shielded: non-crit and `dwCoidHi==dwCoidLo` → strcat `"(Shielded)"`, channel **0x16** | **Confirmed** |
| Case 1 repair: amount **negated** (`-param_2[2].dwCoidLo`), channel **0x13** | **Confirmed** |
| Case 2 power: channel **0x15**; uses `"Saps"` / Gains / Loses | **Confirmed** |
| Case 3 XP: `DAT_00a43258` → `"XP"`, channel **0x14** | **Confirmed** |
| Default channel **0x11** | **Confirmed** |
| Append only if msg non-empty && `DAT_00d1b8dc` | **Confirmed** — style `&DAT_00a1419b`, gm=`0` |
| Sole caller shape: `FUN_0093ffb0` @ `0x00940e37` | **Accepted on dual live callers/xrefs** (not re-queried this session) |
| Product/PDB name known | **Fails** — `_Inferred` required |
| Runtime Confirmed | **Fails** — Terminal false; no Launcher |

### Channel map (re-derived from frozen raw)

| Code | Path in raw |
|---|---|
| `0x12` | dodge / miss / resist / deflect plates |
| `0x10` | crit (`bPad0!=0`) after damage format |
| `0x11` | normal damage (non-crit, hi≠lo) or default |
| `0x16` | non-crit + hi==lo → `(Shielded)` |
| `0x13` | case 1 repair |
| `0x15` | case 2 power |
| `0x14` | case 3 XP |

Matches dual sealed map exactly.

### Adversarial attacks (EmitEventLine)

| # | Attack | Result |
|---|---|---|
| 1 | Skill cast / damage apply residual | **Fails** — format + `CDlgChatLog_AppendChannelMessage` only |
| 2 | `__thiscall` host in ECX | **Fails** — stack arg0; `ret 8` |
| 3 | Channel 0x12 is “miss only” | **Fails** — also Dodges / Resists / Deflects |
| 4 | Heal amounts stored positive | **Fails** — case 1 uses **negated** amount |
| 5 | Always emits world combat | **Fails** — multi-stage local/related/crew gates |
| 6 | Case 3 is currency not XP | **Fails** — `DAT_00a43258` = `"XP"` (dual `read_memory`) |
| 7 | `DAT_00a84270` is “Deflects An Attack” | **Fails** — plate is `"for"` (deflect is separate English) |
| 8 | Event blob is pure `TFID_16*` only | **Fails as sole type** — overlay: 2×TFID + amount/flags + type dword; product struct open |
| 9 | Product English sealed | **Fails** — `_Inferred`; event/option-global English open |
| 10 | Runtime Confirmed without Launcher | **Fails** — dual correctly leaves Terminal false |

### Soft niggles (not sealed-claim failures)

1. **Clean is abbreviated** — named clean documents ABI/gates/channels/callees and defers full sprintf switch to raw. Header explicitly says bit-exact OPEN and “transcribe the raw switch body.” Dual seal is against raw, not full clean transcription. Acceptable for `_Inferred` dual, but port implementers must **not** ship clean alone.
2. **Self-dodge block in clean** documents the condition but the if-body has comments only (no `return;`). Raw has the real early return. Documentation hazard only; dual B already flags self-dodge bit-exact as residual risk.
3. **Clean `FUN_005749d0` C declaration** is not a true thiscall prototype (ECX=crew host). Comments state the convention; raw + peer dual seal the this-pointer.
4. **`DAT_00af921c` product role** remains open (bit CF real; month-table symbol collision dual-flagged). Correctly not Confirmed as options UI.

### Unit A dual quality

**PASS** — keep **`accept-with-gaps`**.

Sealed CF/ABI/role/channels/strings/type switch/repair negation all re-derived from frozen raw and match dual A/B/report. Gaps dual already flags (product event struct, option-global English, `+0xF40`/`DAT_00d1b644` English, runtime) remain fair. Terminal **false**.

---

## Unit B — `0x0082fb30` UI_InteractionMenu_AddConvoyInviteOrKick_Inferred

### Body / ABI / role seal (independent)

| Claim | Independent result |
|---|---|
| Range half-open `0x0082fb30`–`0x0082fc31` (**257 B** / `0x101`) + `CC` pad | **Confirmed** — size math + dual meta |
| Entry compares **`[edx+0x6B4]`** → EDX = target | **Confirmed** — dual entry plate `83 BA B4 06 00 00 01` |
| ESI = menu host (`unaff_ESI`); stores `ESI[0x150]`/`[0x151]` | **Confirmed** — raw body; offsets **+0x540 / +0x544** (`0x150*4` / `0x151*4`) |
| Epilogue **`pop edi; ret`** (`5F C3`) — no stack cleanup | **Confirmed** — dual re-verify |
| **Not** standard `__thiscall` | **Confirmed** — register contract parent-preserved; bare `ret` not `ret 4` |
| Decompiler `param_1` / `__fastcall` phantom | **Confirmed as noise** — unused; dual B correctly attacks |
| Gate: enter if `target+0x6B4 < 1` **or** `local+0x6B4 > 0` | **Confirmed** — raw boolean form |
| Invite if `*(local+0xCB0)==0` **or** `!ContainsMember(target)` | **Confirmed** — exclusive else Kick |
| Plate `i_m_int_2d_btn_generic.xml` | **Confirmed** |
| Invite id **`0x11171`**, label `"Invite To Convoy"` → store `+0x540` | **Confirmed** |
| Kick id **`0x11172`**, label `"Kick From Convoy"` → store `+0x544` | **Confirmed** |
| Create via host `vtbl+0x444`; label `vtbl+0x1D8`; disable `vtbl+0xD4(0)` | **Confirmed** |
| Disable when `FUN_00574880() != DAT_00d1b6d8` (invite also requires crew host non-null) | **Confirmed** — disable ≠ destroy; pointer still stored |
| Caller `FUN_0082fe20` ×2 sites | **Accepted on dual callers** (not re-queried this session) |
| Crew this = `*(local+0xCB0)` for `FUN_005749d0` | **High** — peer dual `VehicleCrew_ContainsMember_Inferred` + pattern; decompiler hides ECX |
| Product menu class / `+0x6B4` English | **Open** — dual gaps correct |
| Runtime Confirmed | **Fails** — Terminal false |

### Adversarial attacks (AddConvoyInviteOrKick)

| # | Attack | Result |
|---|---|---|
| 1 | Skill-cast residual (WQ-009 core) | **Fails as cast** — pure UI button factory; residual consumer of crew dual only |
| 2 | Standard `__thiscall` ECX=this | **Fails** — EDX target; ESI host; bare `ret` |
| 3 | Always creates both Invite and Kick | **Fails** — exclusive branch |
| 4 | `FUN_005749d0` this = target | **Fails** — this is crew host `*(local+0xCB0)`; stack candidate = target |
| 5 | Disable destroys button | **Fails** — `vtbl+0xD4(0)` only; slot still holds pointer |
| 6 | Plate string alone proves product class name | **Fails** — widget XML only; role from Invite/Kick English |
| 7 | `+0x6B4` sealed as character level | **Fails** — numeric gate only; English open |
| 8 | Product name retail-known | **Fails** — `_Inferred` |
| 9 | Invite when already in crew | **Fails** — Kick path requires ContainsMember true |
| 10 | Runtime Confirmed | **Fails** — no Launcher; Terminal false |

### Soft niggles (not sealed-claim failures)

1. **Clean adds null guards** on `DAT_00d1b6d8` that raw does not — slightly safer than EXE CF; bit-exact OPEN already declared.
2. **“Leader” English** for `FUN_00574880()!=local` is **High/inferred** (dual A Confirmed “not leader” wording; dual B High). Slot dual `FUN_00574880` still undualed — correctly gapped.
3. **Parent ESI contract** is fragile without dual of `FUN_0082fe20` — dual flags; not OWN.
4. Scaffold twin `FUN_0082fb30.cpp` retains decompiler `__fastcall`/`param_1` noise; named clean is preferred (dual supersedes plate-only `UI_int_btn_generic_0082fb30`).

### Unit B dual quality

**PASS** — keep **`accept-with-gaps`**.

Sealed CF/strings/IDs/slots/Invite-vs-Kick/crew branch all re-derived from frozen raw and match dual A/B/report. Gaps dual already flags (menu host product class, `+0x6B4` English, undualed `FUN_00574880`/`FUN_0082fe20`, runtime) remain fair. Terminal **false**.

---

## Cross-unit dual report quality

| Check | Result |
|---|---|
| Dual report verdicts match A/B | **Yes** — both units **accept-with-gaps** on A, B, and report plate |
| Terminal false honesty | **Yes** — no runtime Confirmed claimed |
| OWN scope discipline | **Yes** — only `0x007ffef0` / `0x0082fb30`; no parent ledger edits claimed |
| Tool discipline (dual) | **Yes** — dual reports decompile + `read_memory` + callers; **no** `disassemble_bytes` |
| Decompiler artifact honesty | **Yes** — 007ffef0 TFID overlay + not-thiscall; 0082fb30 `unaff_ESI` / phantom `param_1` / not-thiscall |
| Role separation | **Yes** — combat **chat** residual vs interaction-menu **convoy** residual; neither is cast sim |
| Shared crew dual | **Yes** — both consume `VehicleCrew_ContainsMember_Inferred` (`+0xCB0` pattern) without OWN rewrite of that dual |
| Clean sources meaningful names | **Yes** — supersede scaffold aliases; 007ffef0 clean intentionally non-full-switch |
| AutoCore port notes | **Accurate** — channels `0x10`–`0x16`; Invite/Kick ids/slots; ESI/EDX contract; Terminal false |

```text
FUN_0093ffb0 (floater + chat)
  └─ Client_CombatChat_EmitEventLine_Inferred (0x007ffef0)
        ├─ Object_ResolveFromTFID / TFID_* / FUN_0040aff0
        ├─ VehicleCrew_ContainsMember_Inferred (×4 paths)
        └─ CDlgChatLog_AppendChannelMessage (channels 0x10–0x16)

FUN_0082fe20 (interaction menu button packs)
  └─ UI_InteractionMenu_AddConvoyInviteOrKick_Inferred (0x0082fb30) ×2
        ├─ VehicleCrew_ContainsMember_Inferred (Invite vs Kick)
        └─ FUN_00574880 (non-leader disable)
```

---

## Confirmations

1. WQ9D-I dual A/B + report seals for both VAs are **faithful** to frozen raw CF + dual-published live re-verify byte plates.
2. `007ffef0`: chat-only role, **`ret 8`**, channels **0x10–0x16**, type 0..3, repair negation, XP plate, relevance/crew spam gates — **confirmed** from raw walk.
3. `0082fb30`: Invite/Kick exclusive, ids **0x11171/0x11172**, slots **+0x540/+0x544**, EDX target / ESI host, bare **`ret`** — **confirmed** from raw walk.
4. Decompiler hazards dual documents (thiscall cast claims; TFID-only event type; phantom fastcall param; dual-button always-create) are **real and correctly rejected**.
5. Product English residual and runtime remain open by design; Terminal **false**.

---

## Gaps (remain open — dual already owns)

| Gap | Unit | Blocks accept? |
|---|---|---|
| Product / MSVC demangle | Both | No (`accept-with-gaps`) |
| Full product combat-event struct name | `007ffef0` | No |
| English for host `+0xF40` / `DAT_00d1b644` | `007ffef0` | No |
| `DAT_00af921c` options vs month-table label | `007ffef0` | No |
| Product menu-host class | `0082fb30` | No |
| English for `+0x6B4` | `0082fb30` | No |
| Dual of `FUN_00574880` / parent `FUN_0082fe20` | `0082fb30` (support) | No |
| Runtime / bit-exact / differential | Both | No (policy; Terminal false) |
| Live Ghidra re-read by this ADV session | Process | No — dual live plates + raw body sufficient for CF seal audit |

---

## Pass / fail

| Unit | Dual verdict | ADV result |
|---|---|---|
| `0x007ffef0` Client_CombatChat_EmitEventLine_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x0082fb30` UI_InteractionMenu_AddConvoyInviteOrKick_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |

### Overall

**PASS** — WQ9D-I dual seals hold under independent raw CF audit + dual-published live re-verify byte plates + A/B/report consistency check. No sealed-claim failure requiring dual rewrite or verdict downgrade. Soft niggles limited to abbreviated clean 007ffef0 and clean null-guards on 0082fb30 (already bit-exact OPEN). Terminal remains **false**.

---

## Process notes

- Independent ADV verifier; **not** WQ9D-I author.
- Tools this session: full dual report + A/B + named/scaffold function records + raw/annotated/clean + scratch notes; end-to-end frozen raw CF walk.
- Live Ghidra MCP/HTTP **not** reachable from this agent tool surface; dual’s 2026-08-04 `decompile`/`read_memory`/callers plates treated as secondary sealed evidence only after independent CF confirmation of raw bodies.
- **No** `disassemble_bytes`. **No** parent ledger / WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG edits. **No** dual A/B rewrite.
- Output: `docs/reconstruction/reviews/ADV_wq9d_spotcheck_007ffef0_0082fb30.md` (this file).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

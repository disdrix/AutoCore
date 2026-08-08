# Dual A/B report — WQ9D-I OWN-ONLY (`0x007ffef0`, `0x0082fb30`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9D-I**  
**Scope:** VAs `0x007ffef0`, `0x0082fb30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/callees + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth_partition_map.md` → **WQ9D-I**.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities nested consumers).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007ffef0` Client_CombatChat_EmitEventLine_Inferred | **accept-with-gaps** — CF/ABI/channels/strings/caller sealed; product event struct + option-global English open |
| `aa_0082fb30` UI_InteractionMenu_AddConvoyInviteOrKick_Inferred | **accept-with-gaps** — CF/strings/IDs/slots/crew branch sealed; product host class + `+0x6B4` English open |

Path A (fidelity): both **accept-with-gaps** as above.  
Path B (adversarial): no CF rejects; cast-sim misrole and thiscall claims falsified; product names remain `_Inferred`.

---

## Sealed facts — `0x007ffef0`

1. **Body:** `0x007ffef0`–`0x00800ad1` exclusive (**3041 B** / `0xBE1`). Epilogue **`C2 08 00`** → **`ret 8`**.

2. **ABI:** two **stack** args (entry `mov eax,[esp+4]`); **not** thiscall.  
   - `arg0` = client host* (`+0xF40` gate, `+0xE98` local vehicle)  
   - `arg1` = combat-event blob (decompiler `TFID_16*` overlay)

3. **Role:** **Client combat chat emit** — format localized line → `CDlgChatLog_AppendChannelMessage` (`FUN_008f8200`). Not damage sim / cast entry.

4. **Caller (1):** `FUN_0093ffb0` UNCONDITIONAL_CALL @ `0x00940e37` (floater + chat path).

5. **Callees:** `Object_ResolveFromTFID`, `TFID_EqualsObjectId`, `TFID_NotEquals`, `Object_CopyTfid16At228_Inferred` (`FUN_0040aff0` ×4), `VehicleCrew_ContainsMember_Inferred` (`FUN_005749d0` ×4), `Locale_GetInstance_Inferred` (`FUN_007a69d0`), `StringPool_ApplyModeAndRingStore_Inferred` (`FUN_007a6de0`), `sprintf`, `CDlgChatLog_AppendChannelMessage`.

6. **Event overlay (High structural):**  
   - `[0]` source TFID → source name  
   - `[1]` target TFID → target name (**required**)  
   - `[2]` amount + flags (crit/dodge/resist/deflect; hi==lo → shielded)  
   - `[3].dwCoidLo` type: **0** dmg family, **1** repair (negated amount), **2** power, **3** XP

7. **Channels:** `0x10` crit, `0x11` damage, `0x12` dodge/miss/resist/deflect, `0x13` repair, `0x14` XP, `0x15` power, `0x16` shielded.

8. **Constants (`read_memory`):** null TFID `DAT_00a1e850`; `"for"` / `"Hits"` / `"Saps"` / `"XP"`; empty style `DAT_00a1419b`.

9. **Name:** `Client_CombatChat_EmitEventLine_Inferred` — role **High**, product English **Inferred**. Supersedes scaffold `Named_CalleeOf_…_007ffef0`.

10. **Decompile ≡ raw CF** (live 2026-08-04 ≡ frozen 2026-07-23).

### Gaps — `007ffef0`

1. Product/PDB symbol.  
2. Full product combat-event struct name.  
3. English for `+0xF40` / `DAT_00d1b644`.  
4. `DAT_00af921c` bit options vs month-name table label collision.  
5. Runtime / bit-exact open.

### Dual A/B — `007ffef0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` | **accept-with-gaps** |

---

## Sealed facts — `0x0082fb30`

1. **Body:** `0x0082fb30`–`0x0082fc31` exclusive (**257 B** / `0x101`); pad `CC`. Epilogue **`pop edi; ret`** (`C3`).

2. **ABI:** parent-preserved **ESI** = menu host; **EDX** = target (`cmp [edx+0x6B4],1` at entry). Decompiler `param_1`/`unaff_ESI` noise; **not** standard thiscall.

3. **Role:** **Interaction-menu convoy button pack** — create Invite (`0x11171`) or Kick (`0x11172`) via `i_m_int_2d_btn_generic.xml`, store at host `+0x540` / `+0x544`, disable if not leader.

4. **Caller (1):** `FUN_0082fe20` — **2** sites (`0x0082fec7`, `0x0082ff1b`) in both button-build orders.

5. **Branch:**  
   - Invite if `*(local+0xCB0)==0` **or** `!VehicleCrew_ContainsMember(*(local+0xCB0), target)`  
   - else Kick  
   - Labels: `"Invite To Convoy"` / `"Kick From Convoy"`  
   - Disable: `FUN_00574880() != DAT_00d1b6d8` → button `vtbl+0xD4(0)`

6. **Related duals (not OWN):** `VehicleCrew_ContainsMember_Inferred` (`0x005749d0`); slot math peer `ConvoyRoster_GetMemberBySlot_Inferred` (`0x00574760`) vs undualed `FUN_00574880`.

7. **Name:** `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` — role **High** (string plate), product class **Inferred**. Supersedes plate-only `UI_int_btn_generic_0082fb30`.

8. **Decompile ≡ raw CF** (live 2026-08-04 ≡ frozen 2026-07-23).

### Gaps — `0082fb30`

1. Product menu-host class / MSVC name.  
2. English for `+0x6B4`.  
3. Dual of `FUN_00574880` / parent `FUN_0082fe20`.  
4. Runtime / bit-exact open.

### Dual A/B — `0082fb30`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_007ffef0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_007ffef0_FUN_007ffef0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CombatChat_EmitEventLine_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_007ffef0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.md` |
| Annotated | `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_007ffef0_wq9di_notes.md` |

### `aa_0082fb30`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0082fb30_FUN_0082fb30.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0082fb30.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082fb30_FUN_0082fb30.md` |
| Annotated | `docs/reconstruction/raw/aa_0082fb30_FUN_0082fb30.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_0082fb30_wq9di_notes.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007ffef0-0082fb30-wq9di-report.md` |

---

## AutoCore impact

### `007ffef0`

- Port as **client combat-chat presentation**, not sector skill math.  
- Preserve channel codes **`0x10`–`0x16`** into `CDlgChatLog` combat pane.  
- Keep relevance filters (local vehicle / related TFID / crew) so world combat does not flood chat.  
- Repair amounts are **negated** in the event blob; XP case uses string `"XP"`.  
- Pair with dualed `CDlgChatLog_AppendChannelMessage`, TFID leaves, `VehicleCrew_ContainsMember_Inferred`.

### `0082fb30`

- Port as **interaction-menu convoy Invite/Kick** widget factory, not cast residual.  
- Invite id **`0x11171`**, Kick **`0x11172`**, plate `i_m_int_2d_btn_generic.xml`.  
- Crew test: `VehicleCrew_ContainsMember(*(local+0xCB0), target)`.  
- Non-leader disable via roster probe `FUN_00574880` vs local player.  
- Host slots **`+0x540` / `+0x544`**; register contract ESI=host, EDX=target.

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (chat consumer) + convoy/UI notes as appropriate  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

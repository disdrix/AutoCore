# Dual A/B report — MEGA-075 OWN-ONLY (`0x0082f9a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-075**  
**Scope:** VA `0x0082f9a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / system maps / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `get_function_signature` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-075**.  
**Hint:** `UI_InteractionMenu_AddFriendsToggle`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082f9a0` UI_InteractionMenu_AddFriendsToggle | **accept-with-gaps** — CF/ABI/strings/IDs/slots/parent call sites sealed; product menu-host class + `+0x6B4` English + friends-list type open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cast-sim / thiscall / dual-button / phantom-reg claims **falsified**; no CF reject.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082f9a0` — sealed facts

1. **Body:** `0x0082f9a0`–`0x0082fa58` inclusive (**185 B** / `0xB9`); pad `CC` after. Epilogues **`POP ESI; RET`** (`5E C3`).

2. **ABI:** parent-preserved registers — **EAX** = target object\*; **EDI** = menu host\*; void; **`RET`** (`C3`) × exits — **ret 0**, not thiscall. ESI saved for button temp.

3. **Semantics:** interaction-menu **friends toggle** button pack:
   - Gate on object field `+0x6B4` (target < 1 **or** local ≥ 1).
   - If `DAT_00d1da2c` (friends list) non-null and `FUN_00573a30(list, targetName)` hits → create **Remove from Friends** id **`0x1117a`**, store host **`+0x564`**, return.
   - Else → create **Add to Friends** id **`0x11177`**, store host **`+0x558`**.
   - Plate: `i_m_int_2d_btn_generic.xml`; set-text via button `vtbl+0x1d8`.

4. **Caller (1):** dualed `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`FUN_0082fe20`) — **2** UNCONDITIONAL_CALL sites:
   - `0x0082fee3` (order-flag ≠ 0 pack order)
   - `0x0082feff` (order-flag == 0 pack order)
   - Parent sets `MOV EDI,ESI` (host) @ `0x0082feba`; `MOV EAX,EBP` (owner) before each Friends call.

5. **Callees:** direct `FUN_00573a30` only; indirect target name `vtbl+0x160`, menu create `vtbl+0x444`, button text `vtbl+0x1d8`.

6. **Strings (`read_memory`):** `"i_m_int_2d_btn_generic.xml"` @ `0x00a721ac`; `"Remove from Friends"` @ `0x00a72144`; `"Add to Friends"` @ `0x00a72134`.

7. **Name:** `UI_InteractionMenu_AddFriendsToggle` (Ghidra `FUN_0082f9a0`). Role sealed by product UI English; product menu-host MSVC class open. **Retires** plate scaffold `UI_int_btn_generic_0082f9a0`.

8. **Decompile ≡ raw CF** (live 2026-08-05 ≡ frozen 2026-07-23); ABI sealed via `disassemble_function` + parent context + `read_memory`.

### Gaps

1. Product / MSVC class name for menu host and `DAT_00d1da2c`.  
2. English for `+0x6B4`.  
3. Dual of `FUN_00573a30` / name-getter (not OWN).  
4. Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082f9a0_UI_InteractionMenu_AddFriendsToggle.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082f9a0_UI_InteractionMenu_AddFriendsToggle.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082f9a0_FUN_0082f9a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f9a0_FUN_0082f9a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddFriendsToggle.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082f9a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0082f9a0_FUN_0082f9a0.md` |
| Function named | `docs/reconstruction/functions/aa_0082f9a0_UI_InteractionMenu_AddFriendsToggle.md` |
| Prior plate clean (retired role) | `docs/reconstruction/reconstructed-exact/UI_int_btn_generic_0082f9a0.cpp` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed WQ9E-D]
  ├─ shell rebuild FUN_0082d2b0
  ├─ resolve TFID @ host+0x578 → owner EBP
  ├─ pack order via vtbl+0x478:
  │     Ignore  FUN_0082f8d0          [residual]
  │     Friends FUN_0082f9a0          [OWN MEGA-075]
  │     Tell    FUN_0082f810          [residual]
  │     Trade   FUN_0082fc40          [residual]
  │     Clan    FUN_0082fa60          [residual]
  │     Convoy  FUN_0082fb30          [dualed WQ9D-I]
  │     Name    FUN_0082fd50          [residual]
  └─ (reverse order when flag ≠ 0)

FUN_0082f9a0  UI_InteractionMenu_AddFriendsToggle  [OWN MEGA-075]
  └─ FUN_00573a30  friends-list name lookup  [undualed]
       ECX = DAT_00d1da2c; stack = name from target.vtbl+0x160
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082f9a0-mega-075-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082f9a0` | Port as **interaction-menu friends Add/Remove** widget factory, not cast residual. |
| IDs | Add **`0x11177`**, Remove **`0x1117a`**, plate `i_m_int_2d_btn_generic.xml`. |
| Membership | `FUN_00573a30(DAT_00d1da2c, targetName)`; name from target adjustor `vtbl+0x160`. |
| Host slots | **`+0x558`** Add, **`+0x564`** Remove. |
| ABI | **EAX=target**, **EDI=menu**, **ret 0**. Match parent `FUN_0082fe20` register contract (not ECX thiscall). |
| Pair with | dualed parent `0082fe20`; dualed convoy sibling `0082fb30`; residual Ignore twin `0082f8d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history (`UI_int_btn_generic_0082f9a0` → `UI_InteractionMenu_AddFriendsToggle`)
- system notes (interaction menu / social UI; not cast manager)
- WORK_QUEUE / RESUME / CHANGE_LOG / progress / COVERAGE_LEDGER

**Terminal:** false (runtime open; dual seal complete for OWN VA).

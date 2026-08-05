# Dual A/B report — W17-H OWN-ONLY

**Date:** 2026-07-29  
**Agent:** W17-H  
**Scope:** OWN ONLY VAs `0x00944d50`, `0x0090dd50`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger edits.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/callees/meta). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (base `0x400000`). Dual A/B = fidelity vs adversarial reviews.

---

## Verdicts

| Unit | VA | Canonical name | Verdict |
|------|----|----------------|---------|
| `aa_0090dd50` | `0x0090dd50` | `ClientCamera_ApplyModeDistanceBand` | **accept** — leaf mode→distance-band + clamp **sealed** |
| `aa_00944d50` | `0x00944d50` | `Client_ClearObjectReferences` | **accept-with-gaps** — ABI + stage order sealed; panel product types / tree SSA / unnamed callees open |

---

## VA `0x0090dd50` — ClientCamera_ApplyModeDistanceBand

### Sealed facts

1. **ABI:** object in **EAX**; **no** stack args; plain **`RET`**; **leaf** (zero callees).
2. **Mode** at `cam+0x60c`: **0 / 1 / else**.
3. **Writes:** min `+0x524`, max `+0x528`, rate `+0x534`, currents `+0x52c/+0x530`.
4. **Float pool** (`read_memory`): 16, 2, 11, 16, 6, 20, 30, 12, 20; mid factor **0.5**.
5. **Mode table:**
   - 0 → min 2, max 11/16 (`DAT_00d1b26c`); optional secondary init if `*(DAT_00d1b6d8+0x6b9)`
   - 1 → min 6, max 20/30
   - else → min 12, max 20; force currents = 20
6. **Shared clamp** of both currents into `[min,max]`.
7. **Callers:** Respawn Update/dtor, TeleportIn/Out ctors, CreateCharacter, + helpers (12 sites).
8. **Name:** Probable (behavior + callers); not format-string sealed.

### Gaps

- Product mode labels; meaning of `DAT_00d1b26c` / `+0x6b9`; runtime dumps.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0090dd50_FUN_0090dd50.md` |
| Annotated | `docs/reconstruction/raw/aa_0090dd50_FUN_0090dd50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ClientCamera_ApplyModeDistanceBand.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_0090dd50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md` |
| Function alias | `docs/reconstruction/functions/aa_0090dd50_FUN_0090dd50.md` |

---

## VA `0x00944d50` — Client_ClearObjectReferences

### Sealed facts

1. **ABI:** `__thiscall(client, obj*)`; **`RET 4`**; null early-out.
2. **Body:** `0x00944d50`–`0x00945367`.
3. **Role:** multi-system **reference scrub** (not destroy). Distinct from `VOGClient_CompletelyDestroyObject` @ `0x009440e0`.
4. **Stage order:** sticky → related notify → COID tree erase → UI host → select chrome → inventory/mission → sheets → always unbind pair → class 0x0E → `Object_SetSelectedTarget` clear → global dialog/panels → `FUN_00996ff0(COID)`.
5. **Callers (direct):** `ClientSpecialEvent_Respawn_dtor`, `FUN_009791c0`, `FUN_009788b0`.
6. **Named callees:** `Object_SetSelectedTarget`, `InventoryGrid_ContainsItem`, `Vehicle_HasEquippedTFID`, `UiSelectWidget_ApplySelectChrome`, `Client_UI_InventorySheet_RemoveByItem`, `Client_RefreshOpenMissionUiWindows`.
7. **Name:** Probable/inferred (no product string).

### Gaps

- Product method name; full panel types; COID tree node layout; unnamed FUN_* callees; tree-iterator SSA bit-exact (prefer raw); runtime.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00944d50_Client_ClearObjectReferences.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00944d50_Client_ClearObjectReferences.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00944d50_FUN_00944d50.md` |
| Annotated | `docs/reconstruction/raw/aa_00944d50_FUN_00944d50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ClearObjectReferences.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00944d50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00944d50_Client_ClearObjectReferences.md` |
| Function alias | `docs/reconstruction/functions/aa_00944d50_FUN_00944d50.md` |

---

## AutoCore impact

| Unit | Impact |
|------|--------|
| Camera band | Client-only; after special-event mode cookie restore, re-apply zoom min/max/rate. Server need not port unless UI/camera sim. |
| Clear refs | Client UI bookkeeping on object removal (airlift ship teardown). Server destroy paths already authoritative; do not confuse with CompletelyDestroyObject. |

## Constraints honored

- OWN VAs only; no parent ledger edits; no Launcher; no `disassemble_bytes`.

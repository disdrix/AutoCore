# Dual A/B report — WQ7R-A OWN `aa_008ac7a0` + `aa_008aaf60`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ7R-A**  
**Scope:** VAs `0x008ac7a0`, `0x008aaf60` only. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq007_residual_partition_map.md`  
**Work item:** **WQ-007** missions-progression (priority 96) residual seal  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal coverage:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ac7a0` Client_MaybeShowMultiActiveMissionTip_Inferred | **accept-with-gaps** — hash walk + count predicate + tip≥2 + ABI sealed; field/tip English open |
| `aa_008aaf60` Client_MissionDialog_SetHeaderCaption_Inferred | **accept-with-gaps** — ECX/EDI ABI + clear/set CF + vcall order + `+0x1d8(0,1,1)` lag fix sealed; widget English + nested callees open |

---

## VA `0x008ac7a0` — sealed facts

1. **Body:** `0x008ac7a0`–`0x008ac884` (228 B / `0xE4`).
2. **ABI:** no formals; plain **`ret` (`C3`)**; void.
3. **Gate:** `DAT_00d1b6d8 != 0` and `( *(byte*)(DAT_00d1b6d8 + 0xd34) & 1 ) == 0`.
4. **Walk:** active-mission hash at singleton **`+0x540`**, lock **`hash+0x1d`**, chain **`+0x14`**, payload **`node+8`** (HashError:TraversalLock / TraverseToNext / VOG_DEBUG_STOP).
5. **Count iff:** `*(short*)(payload+0xf8) == 0` **and** `*(int*)(payload+0xfc) != -1`.
6. **Tip:** if count **≥ 2** → `Client_MaybeShowFirstTimeTip` tip id **`0x20`**, this **`DAT_00d1a840`**.
7. **Caller (1):** `Client_MissionDialogHandleButton` @ `0x008aec20` (accept-offer after GiveMission / hide / tip `2`).
8. **Not** dialog list refresh (old parent comment wrong); **not** C2S; **not** mission grant.
9. **Name:** `Client_MaybeShowMultiActiveMissionTip_Inferred` (Ghidra `FUN_008ac7a0`). Scaffold `Named_VOG_DEBUG_STOP` discarded.
10. **Decompile ≡ bytes** for CF / threshold / tip id.

### Gaps

- Product / PDB name; tip `0x20` string English.  
- Payload type and product names for `+0xf8` / `+0xfc`.  
- Independent proof gate bit ≡ tip-0x20 FirstFlags.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_MaybeShowMultiActiveMissionTip_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ac7a0.cpp` |
| Function | `docs/reconstruction/functions/aa_008ac7a0_FUN_008ac7a0.md` |
| Function named | `docs/reconstruction/functions/aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` |

---

## VA `0x008aaf60` — sealed facts

1. **Body:** `0x008aaf60`–`0x008ab098` (312 B / `0x138`).
2. **ABI:** **ECX** = dialog context; **EDI** = caption key (**0** = clear); plain **`C3`**; SEH `LAB_009abcb7`.
3. **Widget:** `dialog+0x6e0`; null → entire body no-op.
4. **Clear (EDI==0):** widget vtbl **`+0x1d8(0,1,1)`** then **`+0x34c`**.
5. **Set (EDI≠0):** `007a69d0` → `007a6de0(EDI,-1)` → `std::string` → optional **`FUN_005465c0`** if `DAT_00d1b6d8` → `+0x1d8(0,1,1)` → **`FUN_008aab00(widget)`** → `+0x1f0` → `+0x34c` → cond **`+0x1fc`** if `DAT_00d1b21c==0` **or** state `dialog+0x648` ∈ {**2**,**3**}.
6. **Common tail:** vtbl **`+0x214(0)`** then **`FUN_008aa610`**.
7. **Decompiler lag:** `+0x1d8` is **three** args (bytes `6a 01 6a 01 6a 00`), not single `(0)`.
8. **Callers (6):** `Client_ShowNpcMissionDialogUI`×3, `Client_UpdateMissionJournal`×2, `FUN_0093e450`×1.
9. **Name:** `Client_MissionDialog_SetHeaderCaption_Inferred` (Ghidra `FUN_008aaf60`). Scaffold journal-only name understates call surface.
10. **Nested** `005465c0` / `008aab00` / `008aa610` are sibling residual OWN — call order sealed; bodies not dualed here.

### Gaps

- Product widget class / vtable English.  
- EDI key domain.  
- `DAT_00d1b21c` product meaning.  
- Nested residual dual completion.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008aaf60_FUN_008aaf60.md` |
| Annotated | `docs/reconstruction/raw/aa_008aaf60_FUN_008aaf60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_MissionDialog_SetHeaderCaption_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aaf60.cpp` |
| Function | `docs/reconstruction/functions/aa_008aaf60_FUN_008aaf60.md` |
| Function named | `docs/reconstruction/functions/aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ac7a0` | Client-only UX tip after accept. Honor gate bit, lock byte, exact `+0xf8/+0xfc` filter, threshold ≥2, tip id `0x20`. Do **not** treat as list rebuild or server logic. |
| `008aaf60` | Client dialog header apply/clear. Preserve ECX/EDI register contract and three-arg `+0x1d8`. Full header pipeline still needs residual duals of format/chrome helpers before bit-exact UI port. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Odd behavior preserved; English unproven → `_Inferred`.  
- `terminal_coverage = false`.

# Dual A/B report — W28-J OWN `aa_004bcf90` + `aa_004bce90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-J  
**Scope:** VAs `0x004bcf90`, `0x004bce90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bcf90` CNDHash_Ctor_009cb45c | **accept-with-gaps** — ABI/field init/vtbl/Alloc handoff/COList hashA·hashB callers sealed |
| `aa_004bce90` CNDHash_Ctor_009cb450 | **accept-with-gaps** — same template; distinct stamp; COList tableC always log2=5 sealed |

---

## VA `0x004bcf90` — sealed facts

1. **Body:** `0x004bcf90`–`0x004bd001` (**114 B / `0x72`**); pad `CC` after last instruction.
2. **ABI:** **`__thiscall`**; ECX=`this`; stack **byte log2** (4-byte slot); epilogue **`ret 4`** (`C2 04 00`); **EAX** = `this`.
3. **Role:** CNDHash constructor for object vtbl **`PTR_FUN_009cb45c`** — set `+0x08 = 1<<log2`, store log2 at `+0x1C`, zero standard fields, call AllocBucketTable twin **`FUN_004bc840`**, return this.
4. **sizeof:** **`0x34`** (COList `operator_new(0x34)`).
5. **Unwritten:** **`+0x24`** not stored (same residual as other CNDHash ctors).
6. **Xrefs:** sole consumer `FUN_004bbfb0` COList_Constructor ×2 (`0x004bc042`, `0x004bc07b`) → host **+0x04 / +0x08**.
7. **Name:** `CNDHash_Ctor_009cb45c` (Ghidra `FUN_004bcf90`; stamp-qualified parallel to `CNDHash_Ctor_009ce1a0`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product / PDB English beyond CNDHash stamp.  
- Full vtbl method matrix; AllocBucketTable body `FUN_004bc840` not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcf90_CNDHash_Ctor_009cb45c.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bcf90_CNDHash_Ctor_009cb45c.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb45c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcf90.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcf90_FUN_004bcf90.md` |
| Function named | `docs/reconstruction/functions/aa_004bcf90_CNDHash_Ctor_009cb45c.md` |

---

## VA `0x004bce90` — sealed facts

1. **Body:** `0x004bce90`–`0x004bcf01` (**114 B / `0x72`**); pad `CC` after last instruction.
2. **ABI:** identical to twin — **`__thiscall`**, stack log2, **`ret 4`**, returns this.
3. **Role:** CNDHash constructor for object vtbl **`PTR_FUN_009cb450`** — same field template; AllocBucketTable twin **`FUN_004bc7a0`**.
4. **Twin diff (only):** vtbl imm `50 B4 9C 00` vs `5C B4 9C 00`; call rel → `004bc7a0` vs `004bc840`.
5. **sizeof:** **`0x34`**.
6. **Xrefs:** sole consumer `FUN_004bbfb0` @ `0x004bc0b0` — **always** `FUN_004bce90(5)` → host **+0x18**.
7. **Name:** `CNDHash_Ctor_009cb450` (Ghidra `FUN_004bce90`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / full vtbl matrix; Alloc `FUN_004bc7a0` not OWN.  
- Runtime / bit-exact.  
- Node-layout English (sibling RemoveAll next@+0x0C vs twin family next@+0x10) is context only.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bce90_CNDHash_Ctor_009cb450.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bce90_CNDHash_Ctor_009cb450.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.md` |
| Annotated | `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb450.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bce90.cpp` |
| Function | `docs/reconstruction/functions/aa_004bce90_FUN_004bce90.md` |
| Function named | `docs/reconstruction/functions/aa_004bce90_CNDHash_Ctor_009cb450.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bcf90` | COList hashA/hashB: `new(0x34)` + **`CNDHash_Ctor_009cb45c(log2)`**. Param is **log2**, not count. After ctor, `+0x08` is mask `N-1` (Alloc post-condition). Preserve **ret 4** + return this. Do **not** write `+0x24` in ctor. |
| `004bce90` | COList tableC: **always** `CNDHash_Ctor_009cb450(5)` — different stamp/Alloc than hashA/B. **Do not** substitute `004bcf90`. Preserve **ret 4**. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bbfb0` | COList_Constructor sole caller (W27-L **accept-with-gaps**) |
| `0x004bc840` | AllocBucketTable for stamp `009cb45c` (bucket heads `009cb350`) |
| `0x004bc7a0` | AllocBucketTable for stamp `009cb450` (bucket heads `009cb348`) |
| `0x004bd120` / `0x004bd010` | scalar dtor / RemoveAll-class on vtbl `009cb45c` |
| `0x004bd090` / `0x004bcf10` | scalar dtor / RemoveAll-class on vtbl `009cb450` |
| `0x0051db60` | `CNDHash_Ctor_009ce1a0` parallel template (W26-P) |
| `DAT_00b04830` | global COList host pointer |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Names stamp-qualified (`CNDHash_Ctor_<vtbl>`) per established CNDHash ctor convention; no invented product class beyond family evidence.

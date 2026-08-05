# Dual A/B report — W30-G OWN `aa_004bcd40` + `aa_004bcce0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-G  
**Scope:** VAs `0x004bcd40`, `0x004bcce0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bcd40` CNDHash_Recreate_009cb45c | **accept-with-gaps** — ABI/CF/lock-warn/Free→Alloc chain sealed; zero static callers residual |
| `aa_004bcce0` CNDHash_Recreate_009cb450 | **accept-with-gaps** — twin CF; distinct Free/Alloc; sole caller always log2=5 sealed |

---

## VA `0x004bcd40` — sealed facts

1. **Body:** `0x004bcd40`–`0x004bcd94` exclusive (**84 B / `0x54`**); pad `CC` after last instruction.
2. **ABI:** **`__thiscall`**; ECX=`this`; stack **byte log2** (4-byte slot); epilogue **`ret 4`** (`C2 04 00`).
3. **Role:** CNDHash **Recreate** for object vtbl family **`009cb45c`** — if traversal lock `+0x1D` set, log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"` and **continue**; FreeBuckets twin **`FUN_004bcca0`**; store log2@`+0x1C`, zero head/tail, provisional `+0x08 = 1<<log2`; AllocBucketTable **`FUN_004bc840`** (stamp `009cb350`) → mask.
4. **Xrefs:** **none** static (dead/unreferenced in this image).
5. **Name:** `CNDHash_Recreate_009cb45c` (Ghidra `FUN_004bcd40`; stamp-qualified parallel to multi-family Recreate_*). Reject `Named_VOG_DEBUG_STOP_*`.
6. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
7. **Closes** W29-K residual “Recreate FUN_004bcd40 not OWN”.

### Gaps

- Product / PDB English beyond Recreate string + family stamps.  
- FreeBuckets body `FUN_004bcca0` not OWN.  
- Zero static callers — dead vs dynamic open.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcd40_CNDHash_Recreate_009cb45c.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bcd40_CNDHash_Recreate_009cb45c.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcd40_FUN_004bcd40.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcd40_FUN_004bcd40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_009cb45c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcd40.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcd40_FUN_004bcd40.md` |
| Function named | `docs/reconstruction/functions/aa_004bcd40_CNDHash_Recreate_009cb45c.md` |

---

## VA `0x004bcce0` — sealed facts

1. **Body:** `0x004bcce0`–`0x004bcd34` exclusive (**84 B / `0x54`**); pad `CC` after last instruction.
2. **ABI:** identical to twin — **`__thiscall`**, stack log2, **`ret 4`**.
3. **Role:** CNDHash **Recreate** for object vtbl family **`009cb450`** — same lock-warn + Free→size→Alloc template; FreeBuckets twin **`FUN_004bcc60`**; Alloc **`FUN_004bc7a0`** (stamp `009cb348`).
4. **Twin diff (only):** Free rel → `004bcc60` vs `004bcca0`; Alloc rel → `004bc7a0` vs `004bc840`; log call relocs.
5. **Xrefs:** sole consumer `FUN_004bbeb0` @ `0x004bbeb8` — **always** `FUN_004bcce0(5)` (tableC; N=32 → mask 31).
6. **Name:** `CNDHash_Recreate_009cb450` (Ghidra `FUN_004bcce0`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
8. **Closes** W29-K residual “Recreate FUN_004bcce0 not OWN”.

### Gaps

- Product English; FreeBuckets `FUN_004bcc60` not OWN.  
- Host `FUN_004bbeb0` product role not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcce0_CNDHash_Recreate_009cb450.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bcce0_CNDHash_Recreate_009cb450.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcce0_FUN_004bcce0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcce0_FUN_004bcce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_009cb450.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcce0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcce0_FUN_004bcce0.md` |
| Function named | `docs/reconstruction/functions/aa_004bcce0_CNDHash_Recreate_009cb450.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bcd40` | hashA/hashB Recreate: FreeBuckets_004bcca0 → set log2 + provisional N → AllocBucketTable_009cb350. Param is **log2**, not count. Lock **warns only**. After Alloc, `+0x08` is **mask**. Preserve **ret 4**. **Do not** substitute tableC Free/Alloc. No static retail callers observed. |
| `004bcce0` | tableC Recreate: FreeBuckets_004bcc60 → Alloc_009cb348. Host always **log2=5**. **Do not** substitute `004bcd40` twins. Preserve **ret 4**. Does **not** preserve entries. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bcf90` | `CNDHash_Ctor_009cb45c` (W28-J **accept-with-gaps**) |
| `0x004bce90` | `CNDHash_Ctor_009cb450` (W28-J **accept-with-gaps**) |
| `0x004bc840` | `CNDHash_AllocBucketTable_009cb350` (W29-K **accept-with-gaps**) |
| `0x004bc7a0` | `CNDHash_AllocBucketTable_009cb348` (W29-K **accept-with-gaps**) |
| `0x004bcca0` / `0x004bcc60` | FreeBuckets twins (not OWN) |
| `0x004bbeb0` | sole static caller of `004bcce0` (always bits=5) |
| `0x004bbfb0` | COList_Constructor (W27-L) |
| `0x0051d230` | parallel medal `CNDHash_Recreate` |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Names stamp-qualified (`CNDHash_Recreate_<object_vtbl>`) per established multi-family Recreate convention; no invented product class beyond family evidence.

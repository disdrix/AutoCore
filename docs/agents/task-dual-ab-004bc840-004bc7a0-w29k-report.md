# Dual A/B report — W29-K OWN `aa_004bc840` + `aa_004bc7a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-K  
**Scope:** VAs `0x004bc840`, `0x004bc7a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bc840` CNDHash_AllocBucketTable_009cb350 | **accept-with-gaps** — dual alloc + mask + stamp/gate/callers sealed |
| `aa_004bc7a0` CNDHash_AllocBucketTable_009cb348 | **accept-with-gaps** — twin CF; distinct stamp; ctor+Recreate sealed |

---

## VA `0x004bc840` — sealed facts

1. **Body:** `0x004bc840`–`0x004bc8d0` (**145 B**); pad `CC` after last instruction.
2. **ABI:** **`__thiscall`**; ECX=`this`; no stack args; success **`pop edi/esi/ecx; ret`**; fail noreturn throw.
3. **Role:** CNDHash AllocBucketTable for sentinel stamp **`PTR_LAB_009cb350`** — gate log2 `+0x1C` ∈ **[1,16]**; `N=*+0x08`; `new[](N*4)` → `+0x10`; `malloc(N*0xC)` slab; each sentinel stamp **`009cb350`**, heads 0; **`+0x08 = N-1` (mask)**.
4. **Fail:** `VOG_DEBUG_STOP` + throw **`0x80004003`** / ThrowInfo `0xacc430`.
5. **Callers (2):** ctor `CNDHash_Ctor_009cb45c` (`FUN_004bcf90`) @ `0x004bcfea`; Recreate `FUN_004bcd40` @ `0x004bcd8c`.
6. **Name:** `CNDHash_AllocBucketTable_009cb350` (Ghidra `FUN_004bc840`). Reject `Named_VOG_DEBUG_STOP_*`.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
8. **Closes** W28-J residual “AllocBucketTable body FUN_004bc840 not OWN”.

### Gaps

- Product / PDB English beyond AllocBucketTable role.  
- Full sentinel vtbl method matrix at `009cb350`.  
- FreeBuckets twin body not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bc840_CNDHash_AllocBucketTable_009cb350.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bc840_CNDHash_AllocBucketTable_009cb350.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bc840_FUN_004bc840.md` |
| Annotated | `docs/reconstruction/raw/aa_004bc840_FUN_004bc840.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009cb350.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc840.cpp` |
| Function | `docs/reconstruction/functions/aa_004bc840_FUN_004bc840.md` |
| Function named | `docs/reconstruction/functions/aa_004bc840_CNDHash_AllocBucketTable_009cb350.md` |

---

## VA `0x004bc7a0` — sealed facts

1. **Body:** `0x004bc7a0`–`0x004bc830` (**145 B**); pad `CC` after last instruction.
2. **ABI:** identical to twin — **`__thiscall`**, plain success `ret`, noreturn throw on bad log2.
3. **Role:** CNDHash AllocBucketTable for sentinel stamp **`PTR_LAB_009cb348`** — same field template; stamp imm only structural diff vs twin.
4. **Twin diff (only):** stamp `48 B3 9C 00` (`009cb348`) vs `50 B3 9C 00` (`009cb350`); call relocs for `operator_new[]` / log / throw.
5. **Fail:** same `VOG_DEBUG_STOP` + **`0x80004003`** / ThrowInfo `0xacc430`.
6. **Callers (2):** ctor `CNDHash_Ctor_009cb450` (`FUN_004bce90`) @ `0x004bceea`; Recreate `FUN_004bcce0` @ `0x004bcd2c`.
7. **Name:** `CNDHash_AllocBucketTable_009cb348` (Ghidra `FUN_004bc7a0`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
9. **Closes** W28-J residual “Alloc FUN_004bc7a0 not OWN”.

### Gaps

- Product English / full sentinel vtbl matrix at `009cb348`.  
- FreeBuckets twin body not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bc7a0_FUN_004bc7a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bc7a0_FUN_004bc7a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009cb348.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc7a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bc7a0_FUN_004bc7a0.md` |
| Function named | `docs/reconstruction/functions/aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bc840` | After ctor/Recreate sets `N=1<<log2` at `+0x08`, call Alloc: validate log2 1..16; allocate pointer table + contiguous 0xC sentinels stamped **`009cb350`**; convert count→mask. Free path must `free(*buckets)` then `delete[]` table. **Do not** use stamp `009cb348`. |
| `004bc7a0` | Same layout for tableC family with stamp **`009cb348`**. COList always ctor(log2=5) → N=32 → mask 31 after Alloc. **Do not** substitute `004bc840`. Preserve throw on bad log2. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bcf90` | `CNDHash_Ctor_009cb45c` sole ctor caller of `004bc840` (W28-J **accept-with-gaps**) |
| `0x004bce90` | `CNDHash_Ctor_009cb450` sole ctor caller of `004bc7a0` (W28-J **accept-with-gaps**) |
| `0x004bcd40` | Recreate for stamp `009cb45c` family → `004bc840` |
| `0x004bcce0` | Recreate for stamp `009cb450` family → `004bc7a0` |
| `0x0051ba40` | `CNDHash_AllocBucketTable_009ce090` parallel medal Alloc (W25-F) |
| `0x00413d80` | `CNDHash_AllocBucketTable_Inferred` parallel other stamp |
| `0x004bbfb0` | COList_Constructor host of both ctor twins |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Names stamp-qualified (`CNDHash_AllocBucketTable_<sentinel>`) per established CNDHash Alloc convention; no invented product class beyond family evidence.

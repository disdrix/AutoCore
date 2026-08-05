# Dual A/B report — W31-M OWN `aa_004bcca0` + `aa_004bcc60`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-M  
**Scope:** VAs `0x004bcca0`, `0x004bcc60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bcca0` CNDHash_FreeBuckets_009cb45c | **accept-with-gaps** — ABI/CF/callers/slab-free sealed; reclaim callee residual; body shared beyond primary stamp |
| `aa_004bcc60` CNDHash_FreeBuckets_009cb450 | **accept-with-gaps** — twin CF reloc-only; 2 callers sealed; reclaim callee residual |

---

## VA `0x004bcca0` — sealed facts

1. **Body:** `0x004bcca0`–`0x004bccd4` exclusive (**52 B / `0x34`**); pad `CC` after last instruction.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall` ECX); no stack args; plain **`ret`** (`C3`).
3. **Role:** CNDHash **FreeBuckets** for primary object family **`009cb45c`** — `count(+0xC)=0` → owning reclaim **`FUN_004e2bd0`** → if `buckets(+0x10)`: `free(*buckets)` sentinel slab + `delete[]` table + null.
4. **Not full dtor:** freelist `+0x20` and list ends untouched; dtor follows with `FUN_0059c8a0`.
5. **Callers (4):** Recreate `CNDHash_Recreate_009cb45c` (`FUN_004bcd40`) @ `0x004bcd66`; Dtor `FUN_004bd140` (vtbl `009cb45c`) @ `0x004bd18e`; parallel Recreate `FUN_004e4990` @ `0x004e49b6`; Dtor `FUN_004e66a0` (vtbl `009cc6c0`) @ `0x004e66ee` — **body shared**.
6. **Name:** `CNDHash_FreeBuckets_009cb45c` (Ghidra `FUN_004bcca0`). Reject `Named_CalleeOf_Named_VOG_DEBUG_STOP_*`.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
8. **Closes** W30-G residual “FreeBuckets body FUN_004bcca0 not OWN” / W29-K FreeBuckets residual.

### Gaps

- Product / PDB English beyond FreeBuckets role.  
- Full value-ownership matrix inside reclaim `FUN_004e2bd0` (not OWN).  
- Shared body with `009cc6c0` — stamp is primary, not exclusive.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcca0_FUN_004bcca0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcca0_FUN_004bcca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets_009cb45c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcca0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcca0_FUN_004bcca0.md` |
| Function named | `docs/reconstruction/functions/aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md` |

---

## VA `0x004bcc60` — sealed facts

1. **Body:** `0x004bcc60`–`0x004bcc94` exclusive (**52 B / `0x34`**); pad `CC` after last instruction.
2. **ABI:** identical to twin — **`__thiscall`**, plain `ret`.
3. **Role:** CNDHash **FreeBuckets** for object family **`009cb450`** (tableC) — same count→reclaim→slab/table free template; reclaim twin **`FUN_004bcae0`**.
4. **Twin diff (only):** reclaim rel → `004bcae0` vs `004e2bd0`; `operator_delete[]` reloc (same absolute `0x0048981c`); free IAT same `0x009c6524`.
5. **Xrefs:** Recreate `CNDHash_Recreate_009cb450` (`FUN_004bcce0`) @ `0x004bcd06`; Dtor `FUN_004bd0b0` (vtbl `009cb450`) @ `0x004bd0fe`.
6. **Name:** `CNDHash_FreeBuckets_009cb450` (Ghidra `FUN_004bcc60`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
8. **Closes** W30-G residual “FreeBuckets FUN_004bcc60 not OWN”.

### Gaps

- Product English; reclaim `FUN_004bcae0` value matrix not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcc60_FUN_004bcc60.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcc60_FUN_004bcc60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets_009cb450.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcc60.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcc60_FUN_004bcc60.md` |
| Function named | `docs/reconstruction/functions/aa_004bcc60_CNDHash_FreeBuckets_009cb450.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bcca0` | FreeBuckets for hashA/hashB (`009cb45c`) path: zero count → reclaim (`004e2bd0`) → `free(*buckets)` slab + `delete[]` table. **Do not** free freelist `+0x20` here (dtor). **Do not** substitute tableC FreeBuckets `004bcc60` / reclaim `004bcae0`. Note body also used by parallel Recreate `004e4990` and dtor `009cc6c0`. |
| `004bcc60` | tableC FreeBuckets: reclaim `004bcae0` → same slab/table free. Pairs with Alloc `009cb348` / Recreate `009cb450`. **Do not** substitute `004bcca0`. Preserve plain `ret`. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bcd40` | `CNDHash_Recreate_009cb45c` (W30-G **accept-with-gaps**) |
| `0x004bcce0` | `CNDHash_Recreate_009cb450` (W30-G **accept-with-gaps**) |
| `0x004bc840` | `CNDHash_AllocBucketTable_009cb350` (W29-K **accept-with-gaps**) |
| `0x004bc7a0` | `CNDHash_AllocBucketTable_009cb348` (W29-K **accept-with-gaps**) |
| `0x004e2bd0` | owning reclaim for `004bcca0` path (node stamp `009cb360`) |
| `0x004bcae0` | owning reclaim for `004bcc60` path (node stamp `009cb358`) |
| `0x004bd140` / `0x004bd0b0` | dtors installing `009cb45c` / `009cb450` |
| `0x0051d150` | medal `CNDHash_FreeBuckets` parallel (W24-H) |
| `0x0059c8a0` | freelist vector teardown after FreeBuckets in dtor |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Names stamp-qualified (`CNDHash_FreeBuckets_<object_vtbl>`) per established multi-family CNDHash convention; no invented product class beyond family evidence.

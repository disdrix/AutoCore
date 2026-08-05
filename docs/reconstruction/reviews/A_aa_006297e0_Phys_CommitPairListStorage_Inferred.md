# Review A (reconstruction fidelity): `aa_006297e0` Phys_CommitPairListStorage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006297e0` |
| **VA** | `0x006297e0`–`0x00629983` |
| **Body** | **420 bytes** |
| **Canonical name** | `Phys_CommitPairListStorage_Inferred` |
| **Prior scaffold** | `FUN_006297e0` / Named_CalleeOf_...CVOGSpawnPoint_Set_006297e0 |
| **Review date** | `2026-07-29` (W27-M dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006297e0_Phys_CommitPairListStorage_Inferred.md` |
| **System** | physics / collision pair storage |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra decompile_function + read_memory + analyze_function_complete + get_function_by_address + xrefs. No disassemble_bytes. No Launcher.

---

## 1. Purpose

Commit dual (ptr,count) pair lists into host pair storage (+0x68 base, +0x6c count, +0x70 capacity, **0x10** stride), optionally growing via DAT_00b05060 tag **0x12**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x006297e0` |
| Bytes | prologue `83 EC 14`; epilogue `C2 10 00` |
| Bounds | 420 B body; pad CC |
| Callers | BindLinks, UnbindLinks, FUN_00629d90 |
| Pair context | A_aa_0055fa40_WorldObj_BindLinks_Inferred; islandStep fn_00561910 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = host; 4 stack args | **Confirmed** | thiscall; ret 0x10 |
| Gate either count nonzero | **Confirmed** | |
| Stride 0x10 | **Confirmed** | <<4 / +0x10 loops |
| Allocator tag 0x12 | **Confirmed** | immediate 0x12 |
| Product English | **Inferred** | |
| Nested 006caaa0 layouts | **Out of scope** | |

---

## 4. Control flow: clean equiv raw equiv live

| Stage | Match |
|---|---|
| Early gate | Yes |
| Dual FUN_006cad30 | Yes |
| FUN_0055f520 prep | Yes |
| Callback / FUN_006caaa0 | Yes |
| Copy / grow / writeback | Yes |
| FUN_0055f590 | Yes |
| ret 0x10 | Yes |

---

## 5. Gaps / open

1. Product/PDB host class name.
2. BindLinks payload types vs island pairs.
3. local_14 scratch formula.
4. Runtime differential.

**Verdict:** **accept**

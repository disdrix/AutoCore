# Review A (reconstruction fidelity): `aa_004bbfb0` COList_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbfb0` |
| **VA** | `0x004bbfb0`–`0x004bc17f` |
| **Canonical name** | `COList_Constructor` |
| **Ghidra name** | `FUN_004bbfb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-L) |
| **Counterpart** | `reviews/B_aa_004bbfb0_COList_Constructor.md` |
| **System** | client / COList |
| **Evidence pass** | Live Ghidra `decompile_function` + entry/exit/`read_memory` + `get_function_by_address` + `analyze_function_complete` + caller decompile of `FUN_0094a6a0` + vtbl rdata. Twins: body dtor / scalar dtor. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct a **COList** host of size **0x58** with dual optional hashes, one fixed third table, three single-CS list members, and zeroed vector buffer triples. Published globally from client InitInstance.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W27-L) | `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/COList_Constructor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bbfb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bbfb0_COList_Constructor.md` |
| Caller | live decompile `FUN_0094a6a0` + bytes @ `0x0094a7d0` |
| Live | decompile ≡ raw; body 464 B; exit `C2 08 00` |

---

## 3. Signature (sealed)

```c
COList* __thiscall COList_Constructor(COList* self, int capA, int capB);
// ECX=this; ret 8; EAX=this
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bbfb0`–`004bc17f` = **464 B** | **High** |
| vtbl | `C7 06 48 B4 9C 00` → `0x009cb448` | **High** |
| ret 8 | exit `83 C4 10 C2 08 00` | **High** |
| sizeof host | InitInstance `push 0x58` / `operator_new` | **High** |
| production args | `push 10; push 5` → `(5,10)` | **High** |
| product class | rdata `COList::Insert` | **High** |

---

## 4. Control flow (sealed)

```
SEH (LAB_009a1742)
*this = PTR_FUN_009cb448
zero triple bases [0xB/C/D], [0xF/10/11], [0x13/14/15]
clamp caps >= 0; store +0x10/+0x14; flags +0x0C/+0x0D
hashA @+0x04 via FUN_004bcf90 if capA else 0
hashB @+0x08 via FUN_004bcf90 if flag+0x0D else 0
tableC @+0x18 always FUN_004bce90(5)
list×3 @+0x1C/+0x20/+0x24 (0x2C, ICS, vtbl 009cb378)
+0x0E = 0
return this
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl + zero triples | **Yes** | **High** |
| Clamp + flags + caps | **Yes** | **High** |
| Dual optional hash | **Yes** | **High** |
| Fixed third table (5) | **Yes** | **High** |
| Triple CS-list construct | **Yes** (identical block ×3) | **High** |
| InitInstance publish path | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `6A FF 68 42 17 9A 00 … C7 06 48 B4 9C 00` |
| Exit | `83 C4 10 C2 08 00` |
| Call site | `6A 58 … 6A 0A 6A 05 8B C8 E8 …` → new(0x58), ctor(5,10) |
| Vtbl[0] | `@009cb448 = 004bd1b0` |
| Rdata | `"Threw error in COList::Insert\n"` @ `0x009cb464` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Caller | `FUN_0094a6a0` only |
| Callees | `operator_new`, `FUN_004bcf90`, `FUN_004bce90`, `InitializeCriticalSection` |
| Globals | `DAT_00b04830`; client field `+0xD34` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / sizeof / vtbl / CF / InitInstance args | **High** |
| Nested hash ctor product English | **Partial** |
| 0x2C list class name (vs dual-CS TSOL) | **Partial** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for `FUN_004bcf90` vs `FUN_004bce90` tables.
2. Product name for 0x2C single-CS list (vtbl `009cb378`).
3. Full SEH unwind semantics (not required for CF port).
4. Runtime hit verification.

---

## Verdict

**accept-with-gaps** — host ABI/layout/CF/InitInstance contract sealed; nested helper English remains open (not OWN).

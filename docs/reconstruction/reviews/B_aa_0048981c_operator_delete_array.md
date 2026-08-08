# Review B (skeptical / adversarial): `aa_0048981c` operator_delete_array

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048981c` |
| **VA** | `0x0048981c` |
| **Canonical name** | `operator_delete_array` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0048981c_operator_delete_array.md` |
| **System** | CRT universal (inventory-transfer partition seed only) |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Real jumptable / multi-branch body | Bytes = single `FF 25` | **Falsified** jumptable |
| 2 | Recursive self-call implements free | Decomp models IAT JMP as call | **Falsified** — no body |
| 3 | Same as scalar `operator_delete` | Sibling @ `0x00489822` / IAT `[0x009c6694]` | **Falsified** merge |
| 4 | Inventory-only helper | ≥100 xrefs across domains | **Falsified** inventory-only |
| 5 | Noreturn (Ghidra family hazard) | Caller `ADD ESP,4` then continues | **Falsified** noreturn |
| 6 | `__thiscall` / ECX payload | cdecl stack arg0; ECX unused | **Falsified** thiscall |
| 7 | Thunk duals full CRT free algorithm | Only JMP sealed | **Agree** external scope |
| 8 | Scaffold invents CF | Live decomp + bytes + IAT xrefs | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| IAT JMP identity | **Confirmed** | Wrong free path / crash |
| Array vs scalar slot | **Confirmed** | `delete` vs `delete[]` mismatch |
| cdecl / returns | **Confirmed** | Stack imbalance |
| Not inventory product code | **Confirmed** | Over-specialized port |
| CRT internals at this VA | N/A | Must not invent body |

---

## 3. Cross-check against raw / live / bytes

```
0048981c: FF 25 98 66 9C 00   JMP [0x009c6698]
00489822: FF 25 94 66 9C 00   JMP [0x009c6694]   ; scalar sibling — different unit
```

IAT `@0x009c6698` sole indirection from this VA.  
Caller sample `0x0057072d`: `PUSH EAX; CALL 0048981c; ADD ESP,4` — **returns**.

Parent `0x005725a0` uses this for **cell array** free — consistent with array form, not proof of product ownership of the thunk.

### Partition seed trap

R10 map labels system `inventory-transfer` because residual filter walked from InventoryGrid parent. Adversarial: **do not** port this as InventoryGrid API — it is CRT.

### False-noreturn trap

Many duals warn that `operator_delete` contaminates decomp. This unit's own decomp does **not** mark noreturn, but sibling scalar often does. Bytes prove both thunks are ordinary CALLable IAT JMPs.

---

## 4. Surviving contract for AutoCore

```
operator_delete_array(void* p):   // 0x0048981c
  JMP [IAT operator delete[]]

AutoCore must:
  - map to CRT `operator delete[]` / `delete[]` on array allocations
  - keep distinct from scalar `operator_delete` @ 0x00489822
  - preserve cdecl caller cleanup

AutoCore must NOT:
  - invent a local free body at this VA
  - treat as InventoryGrid-specific
  - merge with scalar delete
  - mark noreturn
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| 6 B IAT JMP | **Agree Confirmed** |
| Array delete[] identity | **Agree Confirmed** |
| accept | **Agree** |
| Gaps only external CRT/runtime | **Agree** |

---

## 6. Open questions

1. Exact MSVC CRT build for import target (runtime).
2. None on thunk control flow.

**Verdict:** **accept** — agree with A; all adversarial merges (scalar/inventory/jumptable/noreturn) falsified.

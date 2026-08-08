# Review B (skeptical / adversarial): `aa_004034c0` StdList_InsertN_BeforeNode_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004034c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-134) |
| **Counterpart** | `reviews/A_aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission/debug-specific helper (`Named_CalleeOf_Client_DebugListMissionsStatus_*`) | **Falsified** — body is pure insert-N loop; no mission strings; sole direct caller is list resize `FUN_00402dd0`, which itself has **5** callers beyond debug list |
| 2 | Standard **list thiscall** (ECX=list) | **Falsified as entry ABI** — entry **ECX = val***; list is **first stack** arg. (Callee `004040f0` *is* list thiscall.) |
| 3 | `__cdecl` / no stack cleanup | **Falsified** — epilogue **`RET 0xC`** |
| 4 | Insert **after** node / push_front only | **Falsified** — `004040f0` rewires `where->prev` and `new->prev->next` (insert **before** where); resize uses where=head ⇒ back insert |
| 5 | Vector / tree / map insert-N | **Falsified** — BuyNode `0xC` circular links + `"list<T> too long"` Incsize family |
| 6 | Element size ≠ dword | **Falsified for this chain** — `operator_new(0xC)` copies one dword from `*val` |
| 7 | Decompiler `FUN_004040f0(param_3,param_1)` complete | **Clarify** — missing list this; asm `MOV ECX,[EBP+8]` required |
| 8 | Multiple direct xrefs | **Falsified** — **1** UNCONDITIONAL_CALL @ `0x00402de6` |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-N before node loop | **Confirmed** | Wrong container op in ports |
| ECX=val* / stack list,where,count / RET 0xC | **Confirmed** | Stack imbalance / bad value |
| List family via Incsize string + 0xC node | **High** | Mis-tag as vector |
| Dword payload | **High** | Wrong element width |
| Not mission product English | **Confirmed** | Misleading system maps |
| Exact CRT demangle spelling | **Low** | Name residual only |
| Insert-one / BuyNode dual completeness | **Open** | Callee edge cases |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 CF
asm 2026-08-05 seals ABI (overrides decompiler list-this elision)

55 8B EC 6A FF 68 10 D2 9B 00 64 A1 …   SEH
8B D9                                    EBX = ECX (val*)
8B 75 10                                 ESI = count
8B 7D 0C                                 EDI = where
85 F6 76 12                              TEST/JBE done
53 57 8B 4D 08 E8 …                     PUSH val, where; ECX=list; CALL 004040f0
83 EE 01 … EB EA                         count--; loop
… C2 0C 00                               RET 0xC

Caller 00402de6:
  PUSH count / PUSH head / PUSH list
  LEA ECX, [ESP+14]   ; &stack T
  CALL 004034c0
```

Reject ports that:

- Keep `Named_CalleeOf_*DebugListMissions*` as the primary name.
- Treat entry ECX as the list object.
- Use cdecl without popping 12 bytes.
- Model this as vector `insert(n)` or tree rebalance.
- Assume multi-word element copy inside this VA (copy is in BuyNode).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: std::list<uint32_t>-family _Insert(where, count, val)
// Port: insert `count` copies of `val` before `where` (usually sentinel ⇒ append).

void StdListInsertNBeforeNodeDword(
    ref uint val,           // ECX points here
    StdListDword list,      // stack
    ListNodeDword where,    // stack
    uint count)             // stack; stdcall cleanup 12
{
    for (; count != 0; --count)
        StdListInsertOneBefore(list, where, ref val); // FUN_004040f0
}
```

Pair with:

- resize parent `FUN_00402dd0` (grow → this; shrink → unlink/delete),
- Incsize `FUN_00404840` / twin max families,
- sentinel alloc/destroy duals (`0040fb90` / `00403430` family).

---

## 5. Verdict

Adversarial pass confirms A on CF/ABI/list-insert-N dword / single caller. Gaps = demangle + callee duals + runtime → **accept-with-gaps**.

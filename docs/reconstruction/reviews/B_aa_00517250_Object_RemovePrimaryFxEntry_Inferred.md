# Review B (skeptical / adversarial): `aa_00517250` Object_RemovePrimaryFxEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517250` |
| **VA** | `0x00517250` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-N) |
| **Counterpart** | `reviews/A_aa_00517250_Object_RemovePrimaryFxEntry_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always deletes `fx` even if not in vector | Not-found path `ret 4` before free | **Search-gated** |
| 2 | Same full deactivate as secondary teardown | Callees exclude `004b7150` | **TeardownCore only** |
| 3 | Frees when `fx+9 != 0` | `cmp byte [edx+9],0` / `jne` out | **Gate requires 0** |
| 4 | `operator_delete` noreturn collapses epilogue | Bytes: pop/ret after delete | **Returns** |
| 5 | Capacity `+0x12c` updated | Only `+0x128` decremented | **End only** |
| 6 | Plain `ret` / no stack cleanup | All exits `C2 04 00` | **`ret 4`** |
| 7 | Product name in binary | None | **`_Inferred`** |
| 8 | memmove size wrong (element vs byte) | Bytes: `sar 2` then `*4` via double `add edx,edx` | **Byte count sealed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free gate +9 | **Confirmed** | double-free / leak |
| Not-found no-op | **Confirmed** | accidental free of non-member |
| No DeactivateClear | **Confirmed** | wrong lifecycle vs secondary list |
| Erase / end shrink | **Confirmed** | vector corruption |
| Product English | Tentative | cosmetic |
| Runtime | Open | |

---

## 3. Surviving contract

```
void Object_RemovePrimaryFxEntry_Inferred(void *self, void *fx) // thiscall, ret 4
{
  if (!fx || *(char*)(fx+9) != 0) return;
  it = find fx in [*(self+0x124), *(self+0x128));
  if (!found) return;
  memmove erase; *(self+0x128) -= 4;
  if (entry) { TeardownCore(entry); delete entry; }
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names | No |
| R2 | Exact meaning of `fx+9` | No (polarity sealed) |
| R3 | Whether sticky clear always pairs with found | No (caller) |
| R4 | Runtime golden | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00517250` — CF matches 2026-07-23 raw.  
2. `read_memory` full body — gate, search, memmove IAT, end-4, TeardownCore ECX, **`ret 4`**.  
3. Callers/xrefs — `005179e0`, `CVOGObject_SetInteractSpecialFX`.  
4. Callee set excludes DeactivateClear/StopFinalize.  
5. Cross-check W28-H parent sticky-remove residual.

---

## 6. Falsifications locked in

- **Reject** unconditional free without vector membership.  
- **Reject** equating this helper with secondary full teardown (`00516930`).  
- **Reject** assuming StopFinalize/DeactivateClear is called here.  
- **Reject** inventing product symbols without strings/PDB.

**Verdict:** **accept**

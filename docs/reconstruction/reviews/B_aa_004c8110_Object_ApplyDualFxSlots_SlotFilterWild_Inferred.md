# Review B (skeptical / adversarial): `aa_004c8110` Object_ApplyDualFxSlots_SlotFilterWild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8110` |
| **VA** | `0x004c8110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; product symbol + chain dual residual |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | cdecl/void with stack `param_1` | Entry `mov esi,ecx`; xrefs are MI ECX-adjust thunks | **thiscall** |
| 2 | Returns normally | Epilogue is `lea ecx,[esi-0x430]; jmp 00584330` | **Tail-call** |
| 3 | Single effect slot | Two gates at `-0x27c` and `-0x280` | **Dual slots** |
| 4 | Only calls `00583f10` | Also local host* loop → `004b7030` | **Both** |
| 5 | use_slot_filter=0 like chain | Pushes `1` then `-1` | **Filter on, wild slot** |
| 6 | Same this for chain | `lea ecx,[esi-0x430]` rebases | **Rebased this** |
| 7 | Product name in body | None | **`_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual slots + null gates | **Confirmed** | miss slot |
| Arg pack constants | **Confirmed** | wrong e270 path |
| `00583f10` + local `004b7030` | **Confirmed** | incomplete apply |
| Tail chain rebase | **Confirmed** | wrong sibling fields |
| Product names | Tentative | cosmetic |
| Chain semantics (`00584330`) | Partial | sibling not owned |
| Runtime | Open | |

---

## 3. Surviving contract

```
void Object_ApplyDualFxSlots_SlotFilterWild_Inferred(void *self)  // thiscall, tail
{
  for each effect in {self[-0x27c], self[-0x280]} if effect:
    ForEachHostPtrTablePair(self-0x4c0, 0, effect, 1, -1);
    for host in vector(self, vb(self-0x4fc), -0x3c4, -0x3c0):
      ForEachOwnedBit7(host, 0, effect, 1, -1);
  goto FUN_00584330(self-0x430);
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product C++ names | No |
| R2 | Full dual of `00584330` | No for this VA |
| R3 | effect* as want_stop meaning | Mild — forwarded |
| R4 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x004c8110` — dual blocks match scaffold.
2. `read_memory` — push constants, lea ECX offsets, rel32 calls/jmp sealed.
3. Xrefs — MI thunks at `004cce83` / `0053bc49`.
4. Cross-check W24-D `(0, effect, 1, -1)` sample on this caller.
5. Peek decompile `00584330` — similar shape with filter char **0** (distinct).

---

## 6. Falsifications locked in

- **Reject** treating unit as free/cdecl with stack this.
- **Reject** normal `ret` epilogue (it is tail jmp).
- **Reject** single-slot or fan-out-only models.
- **Reject** claiming filter char 0 (that is the chain unit).

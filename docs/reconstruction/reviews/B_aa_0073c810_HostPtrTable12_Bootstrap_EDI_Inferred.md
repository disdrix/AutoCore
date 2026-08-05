# Review B (skeptical / adversarial): `aa_0073c810` HostPtrTable12_Bootstrap_EDI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073c810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-E) |
| **Counterpart** | `reviews/A_aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall method on host | **Falsified** — EDI is table; ECX used only as temp for objects |
| 2 | Stack `this*` / argc formals | **Falsified** — plain RET; no arg pops |
| 3 | Decompiler `void` / no formals complete | **Falsified** — `unaff_EDI` is live register formal |
| 4 | Single NestedHash factory only | **Falsified** — 12 heterogeneous slots |
| 5 | Returns constructed object in EAX | **Falsified** — `XOR EAX,EAX` returns 0 |
| 6 | Dead code (0 xrefs) | **Open** — no static xrefs recovered; body is full SEH-heavy production path; neighbor live code in same range |
| 7 | Product name "GfxToolFactory" from neighbor string | **Careful** — sibling `.cpp` path is evidence of neighborhood only; body has no string; keep structural name |
| 8 | Slot count ≠ 12 | **Falsified** — stores through `EDI[0xb]` / `+0x2C` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI table formal | **High** | Wrong ABI |
| 12-slot layout | **High** | Wrong host size |
| NestedHash 0x10/0x18 wiring | **High** | Wrong bag type |
| Product English | **Low** | Naming only |
| Call site | **Open** | Lifecycle ownership |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 862 B hex ends `83c410 c3`.
- Prologue: `51 53 55 56` (ECX EBX EBP ESI) — no EDI push.
- Slot9 call site matches W34-E notes (`new(0x30)` + `FUN_00457ac0` + tail zeros).
- Slot10 matches W34-G sole NestedHashBag caller (`new(0x40)` + `FUN_00457b30`).
- Xref tools: empty set — do **not** invent callers.

---

## 4. Surviving contract for AutoCore

```
// Port as EDI register-table bootstrap (not ECX thiscall):
int BootstrapHostTable12(void **table /* EDI */) {
  table[0]  = NewC4_Vtbl(aa37b4, aa37a8); Init0();
  // ... slots 1..8 dual-vtbl / composites ...
  table[9]  = NewNestedHash0x10_Host30();  InitBag9();
  table[10] = NewNestedHashBag0x18_Host40(); InitBag10();
  table[11] = NewHost14C(); Wire(table[8]);
  return 0;
}
// Host object span for table storage: >= 0x30.
// Do not assume static xrefs exist; may be vtable/indirect.
// Do not hard-name GfxToolFactory without product plate in this body.
```

---

## 5. Verdict

Adversarial pass confirms A on EDI ABI, 12-slot ladder, NestedHash wiring, return 0. Residual callers + product English → **accept-with-gaps**.

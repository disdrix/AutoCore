# Review B (skeptical / adversarial): `aa_004b67d0` NDSpecialFX_StageTargetEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b67d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b67d0_NDSpecialFX_StageTargetEntries_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Applies multi-target combat hits | No `004d78e0` / floaters / `004e1600` | **Falsified** — staging only |
| 2 | Always reallocates entry buffer | Non-null `+0x3C` → delete only; no new alloc | **Survives** as one-shot |
| 3 | Element size is 16 or variable | `param_3 << 5` hard-coded | **Falsified** alternatives — **0x20** sealed |
| 4 | Writes into list heads at `+0x1E0..` | Only `+0x3C/+0x40/+0x48..+0x54` | **Falsified** as list teardown |
| 5 | `operator_delete` is true noreturn | Same Ghidra artifact as FX duals; body ends | **Survives** as decompiler noise |
| 6 | Multiple callers | Xrefs: only `FUN_0056bab0` | **Survives** sole-caller claim |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x004b67d0` matches raw `aa_004b67d0` body: 16B copy, null gate, `operator_new__(count<<5)`, dword memcpy, dead byte tail, delete-on-set path.

Consumer `FUN_004b6980` confirms `+0x3C`/`+0x40`/`+0x48` are later multi-hit inputs, not permanent FX child lists.

---

## 3. Surviving contract

```
// thiscall host
// host[+0x48..+0x57] = *id16 (16 bytes)
// if host[+0x3C]==0 && count>0:
//   host[+0x40]=count; host[+0x3C]=new(count*0x20); memcpy from entries
// else if host[+0x3C]!=0: operator_delete(host[+0x3C])  // no re-stage
```

**Gaps kept:** product host type; entry schema; replace semantics.

**Verdict:** **accept-with-gaps**.

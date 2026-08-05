# Review B (skeptical / adversarial): `aa_0051f4e0` Character_SetLocalVehiclePtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f4e0` |
| **VA** | `0x0051f4e0` |
| **Canonical name** | `Character_SetLocalVehiclePtr_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md` |
| **System** | character / local vehicle |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always vcalls | Null arg stores then returns | **Falsified** always-vcall |
| 2 | Applies paint color | Only pointer store + optional vfunc | **Falsified** paint apply |
| 3 | Inventory cursor root setter | Cursor duals call it as side path; body is `+0xcd0` only | **Falsified** cursor identity |
| 4 | Jumptable = multi-case switch on this | Ghidra warning on indirect; single vfunc slot `+0x158` | **Agree** decompiler noise |
| 5 | Static global | thiscall ECX | **Falsified** static |

---

## 2. Live ≡ raw

```
Live ≡ raw:
  [this+0xcd0] = arg
  if arg: call [arg.vtbl+0x158]
```

---

## 3. Surviving contract

```
// thiscall SetLocalVehicle(Character*, Vehicle* or null)
// Stores +0xcd0; non-null → vehicle vfunc +0x158()
```

**Verdict:** **accept-with-gaps.**

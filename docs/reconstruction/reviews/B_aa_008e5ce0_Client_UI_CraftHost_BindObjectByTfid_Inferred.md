# Review B (adversarial): `aa_008e5ce0` Client_UI_CraftHost_BindObjectByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5ce0` |
| **VA** | `0x008e5ce0` |
| **Canonical name** | `Client_UI_CraftHost_BindObjectByTfid_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial / falsification |
| **Counterpart** | `reviews/A_aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks attempted

| # | Hypothesis | Result |
|---|------------|--------|
| 1 | `param_1` unused / dead | **Falsified** — host reloaded into ECX for `FUN_008e5990` thiscall |
| 2 | cdecl not stdcall | **Falsified** — `RET 0x0C`; callers do not `ADD ESP,0xC` |
| 3 | Invalid test is `lo==−1 \|\| hi==−1` | **Falsified** — `(lo & hi) == −1` requires both all-ones |
| 4 | Always uses cargo find only | **Falsified** — equip table fallback + ResolveObjectTarget |
| 5 | Mission UI refresh naming is correct | **Reject scaffold** — body is inventory TFID bind into craft host |
| 6 | Broken objects never bind | **Partially open** — find path skips broken into equip scan; if Resolve returns non-null broken, bind still runs |
| 7 | Fastcall ECX=host on entry | **Falsified** — host is stack arg0; ECX only set at call to bind |

---

## Residual risks

- Decompiler compound `if` short-circuit is dense; clean C restructures to sequential steps — verify against live if cargo+locker both live with broken first hit.
- `FUN_00522000` decompile (byte from `+0x59a`) may be wrong ABI when called without explicit this — unowned residual.
- Parent `FUN_008e5e00` not dualed; host field map (+0x754 list, +0x7cc object) cited from sibling only.

---

## Confirmations with A

- stdcall triple + invalid clear sealed.
- Find → broken filter → equip → bind sealed.
- Dual verdict align: **accept-with-gaps**.

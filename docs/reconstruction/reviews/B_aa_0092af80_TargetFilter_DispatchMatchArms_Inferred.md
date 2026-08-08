# Review B (adversarial): `aa_0092af80` TargetFilter_DispatchMatchArms_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092af80` |
| **VA** | `0x0092af80` |
| **Canonical name** | `TargetFilter_DispatchMatchArms_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Path B — adversarial / claim falsification |
| **Counterpart** | `reviews/A_aa_0092af80_TargetFilter_DispatchMatchArms_Inferred.md` |
| **System** | inventory-transfer |
| **Verdict** | **accept-with-gaps** |

---

## Claims tested

| # | Hostile claim | Result | Evidence |
|---|---|---|---|
| 1 | Function is void / no meaningful return | **Falsified** | `XOR AL,AL` + sticky `MOV AL,1`; caller `TEST AL,AL` @ after `0x0092bff5` |
| 2 | Pure thiscall (ECX=this, no register ESI formal) | **Falsified** | Body never loads bestOut from stack; uses **ESI**; caller `LEA ESI,[ESP+…]` before CALL |
| 3 | `ret` bare / cdecl `ADD ESP` by caller only | **Falsified** | epilogue `C2 08 00` (`ret 8`) |
| 4 | Return means `*bestOut != NULL` | **Falsified** | AL set on arm **eligibility** even if Resolve returns null / nearest finds nothing |
| 5 | Arms short-circuit after first hit | **Falsified** | No early exit between arms; all positive count gates run in sequence |
| 6 | Direct COID uses empty test `lo==-1 \|\| hi==-1` | **Falsified** | Bytes: `AND` then `CMP …, -1` → empty iff **both** halves all-bits (same `(lo&hi)==-1` plate) |
| 7 | Multi-caller / UI-only inventory grab path | **Falsified** | Single xref UNCONDITIONAL_CALL from `FUN_0092bf60` |
| 8 | Scaffold-only / unknown system with no inventory link | **Falsified** | Dualed child arm is locker-gated CBID nearest (`0x0092adf0`); partition inventory-transfer |
| 9 | `in_EAX`/`unaff_ESI` are decompiler phantoms only | **Falsified** | Call site loads EAX=ctx, ESI=&bestOut; body `MOV EDI,EAX` / `MOV [ESI],…` |
| 10 | Product English name sealed | **Not claimed** | `_Inferred` retained — gap, not overclaim |
| 11 | Runtime Confirmed | **Not claimed** | Terminal false; no Launcher |

---

## Residual risks (accepted gaps)

- Interiors of residual arms may refine field English of `+0x54/+0x80/+0xAC` lists without changing this dispatcher's CF.
- Filter-ctx class may be skill-tracker vs reaction vs mission interact — role still "dispatch match arms".
- Caller `0092bf60` may add policy after return via `FUN_0092b2a0` (not owned).

---

## Verdict

No sealed claim from Path A collapsed under adversarial pressure. Over-claims (hit-found return, thiscall-only, multi-caller, short-circuit) are explicitly rejected.

**Path B: accept-with-gaps.**

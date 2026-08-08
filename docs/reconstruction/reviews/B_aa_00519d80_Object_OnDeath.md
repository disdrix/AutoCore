# Review B (adversarial): `aa_00519d80` Object_OnDeath

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519d80` |
| **VA** | `0x00519d80` |
| **Canonical name** | `Object_OnDeath` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial / gap hunter (OWN-ONLY WQ9R-G) |
| **Counterpart** | `reviews/A_aa_00519d80_Object_OnDeath.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| # | Attack | Outcome |
|---|---|---|
| 1 | Not OnDeath — only delete-queue helper like `Object_QueueDelete` | **Rejected.** Body is far larger; includes owner notify, net mask, type gates, HB spawn, `FUN_004e77d0` dual modes. Product string embeds **`ONDeath`**. |
| 2 | Skill-bank residual (partition wave label) | **Rejected as primary domain.** No skill-id hash / skill-bank vector walk. Neighborhood address only. System = object death lifecycle. |
| 3 | Pure thiscall no stack args | **Rejected.** Epilogue **`C2 04 00`**; callers pass `param_2`; decompiler uses stack formal as gate. |
| 4 | Return type void | **Weak.** Early path `return 0`; epilogue moves AL from stack temp. Treat as status-bearing; exact enum open. |
| 5 | Single class method | **Rejected.** Four distinct DATA vtbl slots store entry. |
| 6 | Decompiler `unaff_EBX`/`unaff_ESI` prove broken CF | **Rejected as CF-break.** SEH/register recovery noise; branch structure and callees match raw; sealed by string + ret size. |
| 7 | `_DAT_00000000` list vcall means always crash | **Rejected as static truth.** Follows `CNDDoubleList_InvokePredicateAndRemove_Inferred` which recovers list head into that register at runtime; known decompiler artifact on this helper family. |
| 8 | `FUN_004e77d0` mode inverted | **Open gap.** Mode 1 when bit12 clear and not global; mode 0 when bit12 set path. English of modes not sealed. |
| 9 | Runtime Confirmed | **Rejected claim.** No Launcher; matrix Open. |

---

## Residual gaps (must not overclaim)

1. Product MSVC demangle / RTTI for the four vtbl owner classes.
2. deathCtx stack formal product name (reason code vs bool).
3. Clonebase type 1 vs 3 English; flag bit12 @ `+0x17c`.
4. `FUN_004e77d0` / `FUN_004cdc80` / `FUN_004d2700` full contracts (not owned).
5. Late return status byte exact mapping.
6. Runtime / bit-exact / differential.

---

## Agreement with A

| Topic | A | B |
|---|---|---|
| Name `Object_OnDeath` | accept | accept (string-sealed) |
| ABI thiscall + ret 4 | accept | accept |
| Multi-vtbl | accept | accept |
| Not skill-bank body | accept | accept |
| Verdict | accept-with-gaps | **accept-with-gaps** |

---

## Verdict

**accept-with-gaps** — adversarial checks do not unseat CF/ABI/string role; English and runtime remain open.

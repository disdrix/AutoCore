# Review B (adversarial): `aa_004cc400` StdMap_OperatorIndex_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc400` |
| **VA** | `0x004cc400` |
| **Review date** | `2026-08-04` (WQ9G-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path B — adversarial) |
| **Counterpart** | `reviews/A_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attack surface / rejected claims

| Claim under attack | Result | Why |
|---|---|---|
| Always-insert (no find) | **reject** | lower_bound + equality branches to `+0x20` without hint call |
| Int-key operator[] | **reject** | hi@+0x14 signed + lo@+0x10 unsigned pair; not SETL int@+0x10 only |
| Insert-or-find returning InsertPair | **reject** | returns mapped*; no inserted bool |
| Hit rewrites mapped | **reject** | hit path only `ADD EAX,0x20`; no store into node |
| Multiple insert-hint callers | **reject** | WQ9F-E sealed sole caller = this VA |
| Val12 / isnil15 family | **reject** | isnil29 / Val24 insert-hint peer |
| `__stdcall` / RET 0 | **reject** | `C2 04 00` thiscall one stack arg |
| Product Named_CalleeOf scaffold | **reject** | structural `_Inferred` only |

---

## Residual risks (not reject)

- Mapped type English beyond aggro-score usage at callers.
- 16 B key storage vs 8 B ordered pair — compare surface only 8 B (documented).
- No runtime golden.

---

## Verdict

**accept-with-gaps** — adversarial paths against wrong ABI/key/role **closed**; English residual remains.

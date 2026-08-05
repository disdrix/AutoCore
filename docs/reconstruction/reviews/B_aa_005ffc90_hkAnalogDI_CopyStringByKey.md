# Review B (adversarial): `aa_005ffc90` hkAnalogDI_CopyStringByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc90` |
| **VA** | `0x005ffc90`–`0x005ffce5` |
| **Canonical name** | `hkAnalogDI_CopyStringByKey` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / gap hunter (OWN-ONLY W25-M) |
| **Counterpart** | `reviews/A_aa_005ffc90_hkAnalogDI_CopyStringByKey.md` |
| **Verdict** | **accept** |

---

## Attack surface

| Claim under test | Attack | Result |
|---|---|---|
| Free function (decomp) | bytes use ECX before any load | **Reject attack** — thiscall |
| Returns strncpy count | EAX from `FUN_00638060(src)` not dst | **Reject** — source strlen |
| Always writes dst | miss path has no call to 00638040 | **Reject** — dst untouched on miss |
| Key is string pointer | passed to open-address uint hash | **Reject** — integer key |
| Multiple callers | analyze xrefs = 1 | **Reject** — sole `hkAnalogDI_vtbl1` |
| Product class invent | only family via caller name | **Name is role-sealed**, not MSVC RTTI |

---

## Residual risks

1. **`strncpy` semantics** (NUL placement when `strlen(src) >= maxlen`) live in `FUN_00638040` / CRT — not re-proven here beyond call shape.  
2. **Hash false-positive** if capacity test differs from miss sentinel — mitigated: `FUN_00650290` returns `mask+1` on miss; `FUN_0065ad10` checks `index <= mask`.  
3. **Naming**: `hkAnalogDI_*` inherits from prior dual of `0x005ffd80`; if that family name is wrong, this inherits the error — still correct as "analog DI object +8 string table".

---

## Port foot-guns

- Do **not** port from decompiler signature alone (missing this).  
- Do **not** treat return as "bytes copied".  
- Preserve **miss → 0 without dst write**.

---

## Verdict

**accept** — no adversarial contradiction to sealed ABI/CF/role. Gaps are product-English only.

# Review B (skeptical / adversarial): `aa_004617a0` StdVector_InsertN_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004617a0` |
| **VA** | `0x004617a0` |
| **Canonical name** | `StdVector_InsertN_RcElem28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W34-P) |
| **Counterpart** | `reviews/A_aa_004617a0_StdVector_InsertN_RcElem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Same as Pod28 / BasicString insert? | **No** — ECX is **value** not vec/count; helpers AddRef/Release; RET C like string but different lifetime |
| Is ECX unused / decompiler-only phantom? | **No** — `8B F1` + `FUN_00461ac0` ESI source; caller `LEA ECX, [esp+…]` before call |
| Is `@+0x10` a raw owning pointer (unique)? | Unlikely — refcount field + dual AddRef/Release; shared |
| Is this `vector<basic_string>`? | **No** — no string IAT; layout is 4 dwords + shared + 3 bytes + dword, not SSO string |
| operator_delete noreturn? | **False** — triad publish continues |
| Ghidra end `00461aba` | Off-by-one; exclusive **`00461abb`**, size **795** |

---

## Residual risks

1. Product T name / gfx domain plate.  
2. AddRef when refcount becomes 1 is unusual vs classic COM AddRef — port must match observed vtbl+4 gate, not invent IUnknown.  
3. Nested destroy `FUN_00461780` / `FUN_00460d70` residual.  
4. No runtime.

---

## Minimal sealed model

```
StdVector_InsertN_RcElem28(value@ECX, vec, where, count):
  local = copy_ctor(value)   // AddRef resource@+0x10
  if count==0: Release(local); ret 0xC
  if size+count > max: throw
  if cap < size+count: 1.5× realloc + RC uninit-copy/fill/destroy
  else: in-place hole or mid (RC assign)
  Release(local); ret 0xC
```

---

## Verdict

Do not unify with Pod28 (trivial) or BasicString insert. **accept-with-gaps**.

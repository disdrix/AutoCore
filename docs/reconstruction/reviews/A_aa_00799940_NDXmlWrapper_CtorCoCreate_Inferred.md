# Review A (reconstruction fidelity): `aa_00799940` NDXmlWrapper_CtorCoCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799940` |
| **VA** | `0x00799940`–`0x007999ba` |
| **Canonical name** | `NDXmlWrapper_CtorCoCreate` (INFERRED; Ghidra `FUN_00799940`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (XML wrapper construct) |
| **Counterpart** | `reviews/B_aa_00799940_NDXmlWrapper_CtorCoCreate_Inferred.md` |
| **System** | shared NDXml / skills bootstrap |
| **Parent chain** | `SkillDefMap_EnsureInitialized` (and NDUI / SpecialFX loaders) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Construct** NDXml-style wrapper and **`CoCreateInstance`** a COM object into `this+4`:

```
*this = &PTR_FUN_00a98338
this[3]=0; this[4]=0; this[1]=0; this[2]=0
hr = CoCreateInstance(CLSID@DAT_00a0f0e0, null, CLSCTX_INPROC_SERVER=1,
                      IID@DAT_00a0f0f0, &this[1])
if (hr >= 0):
    this[1]->vtable[0xfc/4](this[1], 0)   // method at +0xFC, arg 0
    return this
else:
    FUN_007a4480(0, "VOG_DEBUG_STOP")
    _CxxThrowException(hr, ThrowInfo@DAT_00acc430)  // noreturn
```

Bytes push CLSID `00a0f0e0`, IID `00a0f0f0`, `CLSCTX=1`; vtable init `C7 06 38 83 A9 00` (same as release twin).

On success returns **`this` in EAX**. On failure: debug stop string + C++ exception throw.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_00799940_*` |
| Live Ghidra | `decompile_function`, `read_memory` 128 B @ `0x00799940` |
| Twin release | `FUN_007989b0` dual |
| String | `"VOG_DEBUG_STOP"` |
| Callers | EnsureInitialized, NDUIWindow_InitFromInterfaceXml, NDSpecialFX_LoadFromScriptName, … |

---

## 3. Signature (sealed)

```c
NDXmlWrapper * __fastcall NDXmlWrapper_CtorCoCreate(NDXmlWrapper *this);
// ECX=this; returns this on success; throws on CoCreate failure
```

| Global | Role |
|---|---|
| `DAT_00a0f0e0` | CLSID (16 B) |
| `DAT_00a0f0f0` | IID (16 B) |
| `DAT_00acc430` | C++ ThrowInfo |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Zero members then CoCreate into +4 | **Confirmed** | body/bytes |
| CLSCTX_INPROC_SERVER (1) | **Confirmed** | `push 1` |
| Success → vtbl method `+0xFC` with 0 | **Confirmed** | `call [eax+0xfc]` |
| Fail → VOG_DEBUG_STOP + throw | **Confirmed** | decompile |
| Same vtable as ReleaseMembers | **Confirmed** | `00a98338` |
| Product COM type (MSXML version?) | **Open** | need IID decode |
| Throws vs returns HRESULT to caller | **Confirmed throws** | `_CxxThrowException` |

---

## 5. Gaps

1. Decode CLSID/IID at `00a0f0e0` / `00a0f0f0` to product MSXML / custom interface name.
2. What method at vtbl `+0xFC` does (put_preserveWhiteSpace-style?).
3. Runtime seal.

**Verdict:** **accept-with-gaps**

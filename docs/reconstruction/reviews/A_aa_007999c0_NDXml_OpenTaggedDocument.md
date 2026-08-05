# Review A (reconstruction fidelity): `aa_007999c0` NDXml_OpenTaggedDocument

| Field | Value |
|---|---|
| **Stable ID** | `aa_007999c0` |
| **VA** | `0x007999c0`–`0x00799ae0` |
| **Canonical name** | `NDXml_OpenTaggedDocument` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_007999c0_NDXml_OpenTaggedDocument.md` |
| **System** | NDXml / MSXML document open (UI interfaces + special FX scripts) |
| **Verdict** | **accept-with-gaps** — ABI, object fields, CF, return contract sealed; COM slot product names not IDL-proven |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ `get_function_by_address` / callees / callers / xrefs). No `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

Open a file-backed MSXML document on an **NDXml** stack/object instance: **own a copy of the path**, load bytes into the COM `IXMLDOMDocument*` already created by ctor, then **bind a tag string** (`"XML"`, `"NDSpecialFX"`, …) to a child interface and **read a count** at `this+0x0c`.

Return **0** on success (HRESULT-style), **1** on load failure / empty count / non-success path.

Primary static consumers (6 xrefs):

| Caller | Tag (literal) | Role |
|---|---|---|
| `NDUIWindow_InitFromInterfaceXml` `0x007b3710` | `"XML"` @ `0x00a9650c` | UI interface trees |
| `NDSpecialFX_LoadFromScriptName` `0x004a61b0` | `"NDSpecialFX"` @ `0x009ca178` | interact / script FX |
| `FUN_004a6390` / `FUN_004a6670` | same `"NDSpecialFX"` | FX load variants |
| `FUN_00547920` / `FUN_005abba0` | other tags | additional XML open paths |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007999c0_NDXml_OpenTaggedDocument.md` |
| Annotated | `docs/reconstruction/raw/aa_007999c0_NDXml_OpenTaggedDocument.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_OpenTaggedDocument.cpp` |
| Function record | `docs/reconstruction/functions/aa_007999c0_NDXml_OpenTaggedDocument.md` |
| Live decompile | Ghidra `decompile_function` `0x007999c0` — body ≡ raw |
| Live bytes | `read_memory` entry 256 B + tail `@0x00799ab0` |
| Function meta | body `007999c0`–`00799ae0` |
| Callees | `FUN_007b6a20`, `NDXml_LoadDocumentFromPath`, `operator_new[]` / `delete[]`, `FUN_004234e0`, `FUN_004048e0`, `SysFreeString` |
| Callers | 6 sites (above) |
| Layout context (not owned) | ctor `FUN_00799940` @ `0x00799940`, cleanup `FUN_007989b0` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: `this` in **ECX** (`MOV ESI, ECX` @ entry) |
| Stack args | **2** dwords: `pszPath`, `pszTag` (nullable) |
| Epilogue | **`RET 8`** (`C2 08 00`) on both success and fail tails |
| Return | **`int` in EAX**: **0** success, **1** fail (also may pass through non-zero COM HRESULT until empty-count force) |
| Body | `0x007999c0`–`0x00799ae0` |

```c
// Canonical sealed signature (decompiler param_3 is a SEH artifact — unused / not real)
int __thiscall NDXml_OpenTaggedDocument(void *this, char *pszPath, char *pszTag /* may be NULL */);
```

**Call-site proof (NDUIWindow @ `0x007b374a`):**

```
push  0x00a9650c        ; "XML"  = pszTag
push  ebx               ; path
lea   ecx, [esp+14h]    ; this = stack NDXml
call  0x007999c0
```

**NDSpecialFX @ `0x004a6296`:**

```
push  0x009ca178        ; "NDSpecialFX"
lea   eax, [esp+2Ch]    ; path buffer
push  eax
lea   ecx, [esp+18h]    ; this
call  0x007999c0
```

Ghidra prototype still `undefined NDXml_OpenTaggedDocument(void)` — display of callers often **drops** one argument; **bytes + RET 8** own the ABI.

### 3.2 NDXml fields touched — **SEALED**

Cross-check with ctor `FUN_00799940` (`__fastcall` this in ECX):

| Off | Width | Role in this unit |
|---|---|---|
| `+0x00` | `void*` | vtable `PTR_FUN_00a98338` (not written here; set by ctor) |
| `+0x04` | `IUnknown*` / MSXML doc | COM document; passed to `LoadDocumentFromPath`; vtable dispatch `+0xdc` |
| `+0x08` | `IUnknown*` | **out** interface from doc method `vtbl+0xdc` (tag bind) |
| `+0x0c` | `int32` | **out** count/length from iface method `vtbl+0x20`; empty if `< 1` |
| `+0x10` | `char*` | **owned** path string (`delete[]` old, `new[]` + strcpy) |

### 3.3 Control flow — **SEALED**

```
SEH prolog
if this->path(+0x10): delete[] path
this->path = NULL
alloc strlen(pszPath)+1; strcpy into this->path
loader = FUN_007b6a20()                    // process singleton @ DAT_00d20c38
ok = NDXml_LoadDocumentFromPath(loader, this->doc(+4), this->path)
if !ok: return 1

if pszTag == NULL: bstr = NULL
else:
  bstr = FUN_004234e0(pszTag, -1)          // MultiByteToWideChar → SysAllocStringLen
  if bstr == NULL: FUN_004048e0(0x8007000E) // E_OUTOFMEMORY — noreturn throw

hr = this->doc->vtbl[+0xDC](doc, bstr, &this->node(+8))
if hr == 0:
  hr = this->node->vtbl[+0x20](node, &this->count(+0xC))
if this->count < 1:
  hr = 1
SysFreeString(bstr)
return hr
```

| Stage | Match raw ≡ live decompile |
|---|---|
| Path replace (`delete[]` / `new[]` / strcpy) | Yes |
| Singleton loader + `LoadDocumentFromPath` | Yes |
| Tag → BSTR optional; OOM throw | Yes |
| Doc `+0xdc` → node `+0x08` | Yes |
| Node `+0x20` → count `+0x0c` only if hr==0 | Yes |
| Force fail if count `< 1` | Yes |
| `SysFreeString` then return | Yes |
| Load false → return **1** | Yes |

### 3.4 Callees (this unit) — **SEALED names / roles**

| VA / import | Role |
|---|---|
| `operator_delete[]` `0x0048981c` | free prior path |
| `operator_new[]` `0x00489834` | alloc path copy |
| `FUN_007b6a20` `0x007b6a20` | return singleton loader object (`&DAT_00d20c38`) |
| `NDXml_LoadDocumentFromPath` `0x007b6c70` | file → MSXML load into `this+4` |
| `FUN_004234e0` `0x004234e0` | ANSI → BSTR (code-page helper) |
| `FUN_004048e0` `0x004048e0` | throw on OOM (`0x8007000E`) |
| `SysFreeString` | free tag BSTR (safe on NULL) |

### 3.5 Entry / exit machine facts — **SEALED**

Entry (`read_memory` `@0x007999c0`):

```
64 A1 00 00 00 00    mov  eax, fs:[0]
6A FF                push -1
68 04 14 9B 00       push LAB_009b1404
50                   push eax
64 89 25 00 00 00 00 mov  fs:[0], esp
55                   push ebp
56                   push esi
8B F1                mov  esi, ecx          ; this
8B 46 10             mov  eax, [esi+10h]    ; path
…
```

Exit tails (`read_memory` `@0x00799ab0` region):

```
… 8B C6              mov  eax, esi          ; success: return code in ESI
  8B 4C 24 0C        mov  ecx, [esp+0Ch]
  64 89 0D 00 00 00 00
  5F 5E 5D
  83 C4 0C           add  esp, 0Ch          ; SEH frame
  C2 08 00           ret  8

… B8 01 00 00 00     mov  eax, 1            ; load-fail path
  … SEH restore …
  C2 08 00           ret  8
```

### 3.6 Name — **SEALED as product-useful**

Plate / Ghidra name **`NDXml_OpenTaggedDocument`** matches behavior: open path document + bind **tag** string. Not a pure “load file only” (that is sibling `NDXml_LoadDocumentFromPath`).

---

## 4. Gaps / not sealed in this unit

1. **IDL / MSXML method names** for `vtbl+0xdc` (doc) and `vtbl+0x20` (node/list) — offsets sealed; English names **inferred** (tag select / get_length) only.
2. Full NDXml object size beyond fields touched (ctor inits through `+0x10` only observed).
3. Exact semantics of non-zero COM HRESULT when count still ≥ 1 (rare; not observed at call sites that gate on `== 0`).
4. Runtime live process confirmation / bit-exact image diff.
5. Decompiler shows unused `param_3` — **artifact**; do not port a third stack arg.

**Verdict:** **accept-with-gaps**

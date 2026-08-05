# Review A (reconstruction fidelity): `aa_007b3710` NDUIWindow_InitFromInterfaceXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b3710` |
| **VA** | `0x007b3710` |
| **Canonical name** | `NDUIWindow_InitFromInterfaceXml` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007b3710_NDUIWindow_InitFromInterfaceXml.md` |
| **System** | `client-ui` / libND |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Virtual method** (NDUIWindow family **vtbl +0x3a4**) that initializes a window tree from a resolved **interface `.xml` path**: construct a stack MSXML document holder, open the file as tag `"XML"`, then for each root child node call **`NDUIWindow_ApplyXmlNodeAttributes`** and release the node. On open failure or empty document, log and bail with cleanup. **Not** path-resolve under `../interface/` (that is `NDUIWindow_LoadInterfaceFile` @ `0x007b0ef0`). **Not** attribute parsing itself (owned by `ApplyXmlNodeAttributes` @ `0x007b1ec0`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b3710_NDUIWindow_InitFromInterfaceXml.md` |
| Annotated | `docs/reconstruction/raw/aa_007b3710_NDUIWindow_InitFromInterfaceXml.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDUIWindow_InitFromInterfaceXml.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b3710_NDUIWindow_InitFromInterfaceXml.md` |
| Live Ghidra | `decompile_function(0x007b3710)` 2026-07-29; callees; bulk DATA xrefs |
| Call-site context (not owned) | `NDUIWindow_LoadInterfaceFile` @ `0x007b0ef0` dispatches `(*this+0x3a4)(path, 0)` when path ends in `.xml` |
| String anchors | `"Unable to open .xml file for init: %s"` @ `0x00a964e4`; `"Empty interface file %s"` @ `0x00a964cc`; source path `...\libND\NDUIWindow.cpp` line `0x1b9f` |

---

## 3. Signature / ABI

```c
// Virtual: NDUIWindow vtbl +0x3a4 (index 0xE9)
// Known site (LoadInterfaceFile): ECX = window; stack = (resolvedPath, 0)
void __thiscall NDUIWindow_InitFromInterfaceXml(
    NDUIWindow* this,   // ECX — often lost in Ghidra body (see gaps)
    char* path,         // Stack[0x4] — Ghidra param_1; printed as %s on errors
    int reinitFlag      // Stack[0x8] — Ghidra param_2; passed through to ApplyXmlNodeAttributes
);
```

| Claim | Confidence | Notes |
|---|---|---|
| Virtual slot **+0x3a4** | **High** | LoadInterfaceFile plate + decompile: `.xml` → `(*this+0x3a4)(path,0)` |
| Stack formals = **path + flag** | **High** | Ghidra locals: `param_1` Stack[0x4], `param_2` Stack[0x8] |
| `path` is `%s` in open/empty errors | **High** | `piVar1 = param_1` saved before loop reuse; both log sites use `piVar1` |
| `this` is ECX thiscall | **High** | Hundreds of **DATA** xrefs from UI vtables; no direct CALL list |
| `this` used in body (via Apply thiscall) | **Probable** | Apply is `__thiscall` with window as `this`; Init decompile drops ECX |
| Second stack arg often **0** | **High** | LoadInterfaceFile passes literal `0`; Apply uses `param_4==0` for full field reset |
| Return void | **High** | No meaningful EAX use; Ghidra warns undefined return — treat as void |

---

## 4. Control flow (sealed)

```
SEH push (LAB_009b28b1)
FUN_00799940(&stackDoc)              // fastcall/this ctor: vtbl PTR_FUN_00a98338,
                                     // CoCreateInstance MSXML DOM → stackDoc+4
pathSave = path
openRc = NDXml_OpenTaggedDocument(&stackDoc, path, "XML" [, ...])
if openRc != 0:
    DAT_00d1794c = 0
    FUN_007a4480(1, "Unable to open .xml file for init: %s", pathSave)
    FUN_007989b0()                   // stackDoc cleanup / dtor path
    SEH pop; return
DAT_00d1794c = &stackDoc             // current-doc context for INCLUDE etc.
i = 0
while i < stackDoc.childCount:       // local_14 = this+0xc after open
    rc = (*childList+0x1c)(list, i, &nodeOut)   // fetch child; overwrites path slot
    if rc != 0 or nodeOut == null:
        FUN_007a4480(0, "VOG_DEBUG_STOP")  // only on rc!=0
        msg = FUN_0076cec0(&tmp, "Empty interface file %s", pathSave)
        vog_LogMessage("...\libND\NDUIWindow.cpp", 0x1b9f, 3, msg)
        goto cleanup
    NDUIWindow_ApplyXmlNodeAttributes(/*this=window*/, nodeOut, pathSave, reinitFlag)
    (*nodeOut+8)(nodeOut)            // Release / drop ref on child node
    i++
DAT_00d1794c = 0
cleanup:
    stackDoc.vtbl = PTR_FUN_00a98338
    release stackDoc child ptrs (+8, +4)
    operator_delete[](stackDoc.pathCopy at +0x10)
    SEH pop; return
```

### Stack document layout (from ctor + open + cleanup — **High**)

| Stack local | Off | Role |
|---|---:|---|
| `local_20` | +0x00 | vtbl `PTR_FUN_00a98338` |
| `piStack_1c` | +0x04 | COM / IXMLDOMDocument* (CoCreate) |
| `local_18` | +0x08 | Root / child-list interface after open |
| `local_14` | +0x0c | Child count (`int`) |
| `pvStack_10` | +0x10 | Heap path copy (`operator_delete[]` on exit) |

---

## 5. String / global anchors

| Symbol / VA | Value | Role |
|---|---|---|
| `0x00a964e4` | `"Unable to open .xml file for init: %s"` | Open failure (severity 1 via `FUN_007a4480`) |
| `0x00a964cc` | `"Empty interface file %s"` | Null/failed child fetch |
| vog path | `C:\vog\1_code\vog_14_117_branch\libND\NDUIWindow.cpp` | Source file for empty log |
| line | `0x1b9f` (7071 decimal) | Empty-file log line |
| tag literal | `"XML"` | OpenTaggedDocument tag |
| `DAT_00d1794c` | TLS-like current doc ptr | Set to `&stackDoc` during walk; cleared on success end / open fail; Apply INCLUDE saves/restores it |
| `PTR_FUN_00a98338` | stack doc vtbl | Ctor install + cleanup restore |

---

## 6. Callers / callees (own unit)

### Callers

| Kind | Evidence | Role |
|---|---|---|
| **DATA / vtable** | **100+** xrefs into UI vtables (`0x00a3xxxx`–`0x00a9xxxx`) | Shared default method for NDUIWindow-derived classes |
| **Indirect** | `LoadInterfaceFile` → `(*this+0x3a4)(resolvedPath, 0)` | Primary production path for `*.xml` skins |
| **Indirect** | ApplyXmlNodeAttributes `INCLUDE` → same slot | Nested interface load (owned by Apply unit) |
| Direct CALL list | Empty (`get_function_callers`) | Expected for pure virtual default |

### Callees (this VA)

| Callee | VA | Role in this unit |
|---|---|---|
| `FUN_00799940` | `0x00799940` | Stack MSXML document ctor (`CoCreateInstance`) |
| `NDXml_OpenTaggedDocument` | `0x007999c0` | Open path + tag into stack doc |
| `NDUIWindow_ApplyXmlNodeAttributes` | `0x007b1ec0` | Apply each root child to window |
| `FUN_007a4480` | `0x007a4480` | Assert/log helper |
| `FUN_0076cec0` | `0x0076cec0` | Format `"Empty interface file %s"` |
| `vog_LogMessage` | `0x00996dc0` | File/line log |
| `FUN_007989b0` | `0x007989b0` | Open-fail cleanup of stack doc |
| `operator_delete[]` | `0x0048981c` | Free path copy at stackDoc+0x10 |

---

## 7. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + stackDoc ctor | **Yes** |
| OpenTaggedDocument path/`"XML"` + fail log | **Yes** |
| `DAT_00d1794c` set / clear | **Yes** |
| Child iterate + Apply + Release | **Yes** |
| Empty-file log path/line | **Yes** |
| Cleanup releases + `operator_delete[]` | **Yes** |
| No invented network / gameplay | **Yes** |
| ABI: explicit `this` in clean signature | **Gap** — clean matches Ghidra’s 2-stack-param display; real ABI is thiscall + 2 stack args |

Live `decompile_function(0x007b3710)` (2026-07-29) **byte-matches** raw capture body (no material drift).

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = init window from interface XML | **High** | Strings + Apply + LoadInterfaceFile dispatch |
| Name `NDUIWindow_InitFromInterfaceXml` | **High** | Plate + vog path `NDUIWindow.cpp` + vtbl slot |
| Open fail / empty fail paths | **High** | Distinct strings + `vog_LogMessage` |
| Child walk applies attrs then releases node | **High** | Loop body sealed |
| `DAT_00d1794c` = current stack doc during init | **High** | Write sites in this unit; INCLUDE in Apply saves/restores |
| Stack doc = MSXML COM wrapper | **High** | `FUN_00799940` CoCreateInstance |
| Product class English for every sharing vtbl | **Open** | Shared default; many derived classes |
| Exact OpenTaggedDocument formal count in this call | **Probable** | Tag `"XML"` sealed; trailing formals decompiler-thin |
| Whether empty-doc (count==0) is soft-success | **High** | Loop skipped; clear `DAT_00d1794c`; cleanup — **no** empty log when count is 0 |

---

## 9. Gaps / open

1. Ghidra drops **ECX `this`** in the body; seal only via call site + Apply’s thiscall expectation — not via a saved local in the decompile.
2. Full product/RTTI name for every vtable that points here (shared default).
3. Precise semantics of `reinitFlag` beyond “often 0” and Apply’s `param_4==0` full-reset branch (owned by Apply unit).
4. `FUN_007989b0` exact product name (open-fail twin of success cleanup).
5. Bit-for-bit / runtime / differential: **open**.

**Verdict:** Control flow, strings, stack-doc layout, vtbl slot, and dual fail paths sealed for this VA. Residual: lost `this` in decompiler display + flag English. **accept-with-gaps.**

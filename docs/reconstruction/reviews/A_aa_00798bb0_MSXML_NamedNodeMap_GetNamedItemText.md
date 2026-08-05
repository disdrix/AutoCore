# Review A (reconstruction fidelity): `aa_00798bb0` MSXML_NamedNodeMap_GetNamedItemText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00798bb0` |
| **VA** | `0x00798bb0` |
| **Body span** | `00798bb0` – `00798c9d` |
| **Canonical name** | `MSXML_NamedNodeMap_GetNamedItemText` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W17-G; live Ghidra `decompile_function` + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_00798bb0_MSXML_NamedNodeMap_GetNamedItemText.md` |
| **System** | `msxml` / XML attribute helpers |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf helper shared by XML attribute parsers:

1. Optionally `SysAllocString` the attribute name (NULL name → null BSTR; OOM → `FUN_004048e0(0x8007000e)` noreturn).
2. Call **`IXMLDOMNamedNodeMap::getNamedItem`** at **vtbl +0x1c**.
3. On success + non-null node: **`IXMLDOMNode::get_text`** at **vtbl +0x68**, then **`Release`** at **+0x08**.
4. On text success: **`wcscpy(outBuf, textBstr)`**, free both BSTRs, **return 1**.
5. Else free what is held and **return 0**.

Callers (`FUN_00798d00`, `FUN_00798f30`, …) then `swscanf` / parse the wide buffer into typed fields.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00798bb0_FUN_00798bb0.md` (+ live seal append) |
| Annotated | `docs/reconstruction/raw/aa_00798bb0_FUN_00798bb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MSXML_NamedNodeMap_GetNamedItemText.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00798bb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00798bb0_MSXML_NamedNodeMap_GetNamedItemText.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00798bb0` (2026-07-29) |
| Bytes | `read_memory` entry 128 B; epilogue @ `0x00798c90` → `83 C4 14 C3` |
| Bounds | `get_function_by_address` → `00798bb0`–`00798c9d` |
| Callers | `get_function_callers` (~55); sibling decompiles `0x00798d00`, `0x00798f30` |
| Callees | `SysAllocString`, `SysFreeString`, `wcscpy`, `FUN_004048e0` |

**Not performed:** Launcher, live MSXML attach; **no ownership** of typed wrapper VAs.

---

## 3. Calling convention (sealed)

| Slot | Role | Evidence |
|---|---|---|
| **arg0** | `IXMLDOMNamedNodeMap *` | `call [eax+0x1c]` after load |
| **arg1** | `OLECHAR *attrName` | null test + `SysAllocString` |
| **arg2** | `wchar_t *outText` | `wcscpy` dest; Ghidra `unaff_retaddr` |
| **Return** | `char` in **AL** | `B0 01` / `32 C0` |
| **Cleanup** | `__cdecl` | `add esp,0x14; ret` (locals); callers push 3 args |

**Correction:** Ghidra 2-arg signature is **incomplete**. Callers:

```c
// FUN_00798f30
cVar1 = FUN_00798bb0(param_1, param_3, &local_80);
// FUN_00798d00
cVar1 = FUN_00798bb0(param_1, param_2, local_80);
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + cdecl epilogue | **High** | bounds + bytes |
| Three stack args + AL return | **High** | callers + epilogue |
| `getNamedItem` @ `+0x1c` | **High** | slot 7 after IUnknown+IDispatch |
| `get_text` @ `+0x68` | **High** | slot 26 on IXMLDOMNode |
| `Release` @ `+0x08` | **High** | IUnknown |
| SysAllocString / SysFreeString / wcscpy | **High** | imports |
| OOM path `0x8007000e` noreturn | **High** | decompile |
| Product interface names MSXML | **High / Probable** | layout + game MSXML use elsewhere |
| Out buffer capacity | **Open** | no bounds; callers use ~64 wchar stacks |
| Clean ≡ raw CF (with ABI fix) | **High** | named clean corrects formals |
| Runtime | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null name → null BSTR | **Yes** |
| Non-null → SysAllocString / OOM raise | **Yes** |
| getNamedItem | **Yes** |
| Gate `hr>=0 && node!=0` | **Yes** |
| get_text + Release | **Yes** |
| Success wcscpy + free both + return 1 | **Yes** |
| Fail free + return 0 | **Yes** |
| No invent typed parse inside this unit | **Yes** |

### Recovered CF

```c
// char __cdecl MSXML_NamedNodeMap_GetNamedItemText(map, nameW, outW)
BSTR nameB = nameW ? SysAllocString(nameW) : NULL;
if (nameW && !nameB) raise(E_OUTOFMEMORY);
IXMLDOMNode *node = NULL;
if (SUCCEEDED(map->getNamedItem(nameB, &node)) && node) {
  BSTR text = NULL;
  HRESULT hr = node->get_text(&text);
  node->Release();
  if (SUCCEEDED(hr)) {
    wcscpy(outW, text);
    SysFreeString(text);
    SysFreeString(nameB);
    return 1;
  }
  SysFreeString(text);
}
SysFreeString(nameB);
return 0;
```

---

## 6. Gaps

1. Ghidra register recovery (`unaff_*`) — ABI sealed via callers/epilogue, not pure decompiler formals.
2. Whether first arg is always NamedNodeMap vs Element-with-same-slot (call-site inventory residual).
3. No length check on `wcscpy` — port risk if caller under-sizes buffer.
4. Runtime / differential **Open**.

**Verdict:** **accept-with-gaps** — CF + COM shape High; safe shared leaf for AutoCore XML attribute text extraction once 3-arg cdecl contract is used.

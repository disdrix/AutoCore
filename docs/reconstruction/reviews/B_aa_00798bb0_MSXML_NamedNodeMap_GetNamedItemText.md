# Review B (skeptical / adversarial): `MSXML_NamedNodeMap_GetNamedItemText` @ `0x00798bb0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00798bb0` |
| **VA** | `0x00798bb0` |
| **Body span** | `00798bb0` – `00798c9d` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — W17-G; live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_00798bb0_MSXML_NamedNodeMap_GetNamedItemText.md` |
| **System** | `msxml` / XML attribute helpers |
| **Verdict** | **accept-with-gaps** on OWN CF/ABI/COM slots; **needs-more-evidence** on exact interface product branding and buffer policy |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra 2-arg signature is complete | **Falsified** — callers pass **3** args; third is out wide buffer (`wcscpy` dest). Decompiler `unaff_retaddr` is that buffer, not a phantom return address. |
| 2 | `__thiscall` / ECX is the map | **Falsified for ECX** — map is **stack arg0**; body is **cdecl** (`add esp,0x14; ret`). |
| 3 | Function parses ints/floats itself | **Falsified** — only copies text; typed parse is in siblings (`FUN_00798d00` / `00798f30`…). |
| 4 | `vtbl+0x1c` is `get_nodeName` | **Falsified for this call shape** — 2 outbound args `(BSTR, IXMLDOMNode**)` match **NamedNodeMap::getNamedItem**, not nodeName’s single BSTR out. |
| 5 | Always Releases the name BSTR via IUnknown | **Falsified** — name is freed with **`SysFreeString`**, not `Release`. Node uses `Release`. |
| 6 | Success means attribute existed with non-empty text | **Overstated** — success is `hr(get_text)>=0` after non-null node; empty string can still return 1. |
| 7 | Buffer is bounds-checked | **Falsified** — raw `wcscpy`; overflow is caller risk. |
| 8 | Runtime verified against MSXML | **Falsified** — open / deferred. |
| 9 | Prior name “CalleeOf_VOGMapText” is product role | **Overstated** — parent-seed rename only; unit is generic map attribute text fetch. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-arg cdecl + AL 0/1 | **High** | Wrong port ABI breaks every XML loader |
| getNamedItem / get_text / Release offsets | **High** | Wrong slot → AV or silent miss |
| SysAllocString OOM raise | **High** | Missing raise changes fail mode |
| MSXML product branding | **Medium–High** | Could be another dual-interface XML DOM with same layout |
| Out capacity | **Low (policy)** | Buffer overflow if caller undersized |
| Clean ≡ raw CF with ABI correction | **High** | Scaffold only |
| Typed wrappers | **Out of scope** | Dual OWN-only |

---

## 3. Surviving contract for AutoCore

```
ok = MSXML_NamedNodeMap_GetNamedItemText(map, nameW, outW):  // cdecl
  nameB = nameW ? SysAllocString(nameW) : NULL
  if nameW && !nameB: raise(0x8007000e)  // noreturn
  node = NULL
  if SUCCEEDED(map.getNamedItem(nameB, &node)) && node:
    text = NULL
    hr = node.get_text(&text)
    node.Release()
    if SUCCEEDED(hr):
      wcscpy(outW, text)   // NO bounds
      SysFreeString(text); SysFreeString(nameB)
      return 1
    SysFreeString(text)
  SysFreeString(nameB)
  return 0
```

**Port rules that survive adversarial review:**

1. Never drop the third argument — every retail call site supplies an out buffer.
2. Keep HRESULT-style `>= 0` checks (not only `S_OK==0`) — decompile uses signed `hr >= 0`.
3. Do not parse numbers here; leave `swscanf` to wrappers.
4. Size out buffers like retail callers (≥ 64 wchar for known wrappers) or replace `wcscpy` with a deliberate bounded API and document divergence.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs raw body | **Match** (2-arg print residual) |
| Live epilogue cdecl vs annotated | **Match** after ABI correction |
| Named clean vs raw stages | **Match** with explicit 3 formals |
| Parent-seed “VOGMapText” name | **Superseded** by COM-role name |

---

## 5. Open questions (OWN residual only)

1. Confirm every high-traffic caller passes a NamedNodeMap (not Element) as arg0.
2. Maximum attribute text length observed in shipping XML (buffer policy).
3. Whether `FUN_004048e0` is shared `_com_raise_error` (owned elsewhere).
4. Runtime attach to validate vtbl slots against process MSXML module.

**Verdict:** **accept-with-gaps** on OWN control flow, cdecl ABI, and COM call shape; **needs-more-evidence** only for product branding edge cases and buffer sizing policy. Safe shared leaf for AutoCore MSXML attribute text extraction.

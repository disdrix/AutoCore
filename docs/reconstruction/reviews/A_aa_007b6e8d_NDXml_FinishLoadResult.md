# Review A (reconstruction fidelity): `aa_007b6e8d` NDXml_FinishLoadResult

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6e8d` |
| **VA** | `0x007b6e8d` |
| **Body** | `0x007b6e8d`–`0x007b6f81` |
| **Canonical name** | `NDXml_FinishLoadResult` |
| **Prior / alias** | `FUN_007b6e8d`; string residual fail-log name |
| **Review date** | `2026-07-29` (W19-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_007b6e8d_NDXml_FinishLoadResult.md` |
| **System** | client-xml / MSXML load epilogue |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs`, `analyze_function_complete` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Outlined epilogue** of `NDXml_LoadDocumentFromPath` (`0x007b6c70`):

1. Log HRESULT failures with path + code.
2. If load `VARIANT_BOOL != VARIANT_TRUE`, dump `IXMLDOMParseError` (url, line, linepos, reason), free BSTRs, Release.
3. Restore `ExceptionList`; return bool; **`ret 8`** to grand-caller.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b6e8d_FUN_007b6e8d.md` |
| Annotated | `docs/reconstruction/raw/aa_007b6e8d_FUN_007b6e8d.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_FinishLoadResult.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_007b6e8d.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b6e8d_NDXml_FinishLoadResult.md` |
| Parent dual (context) | `NDXml_LoadDocumentFromPath` reviews / clean |
| Live entry bytes | `85 f6 c7 45 fc 00… 7d 14 8b 55 0c **56** 52 68 f0 5e a9 00 6a 01 e8…` |
| Fail string | `0x00a95ef0` = `"Failed to load XML file %s, failed with code %d"` |

---

## 3. Byte seal (critical decomp residual)

Decompiler showed only path for fail log. **Bytes seal second arg:**

```
test esi, esi
mov  [ebp-4], 0
jge  skip
mov  edx, [ebp+0xc]   ; path
push esi              ; HRESULT  ← decomp miss
push edx
push fmt @ 0x00a95ef0
push 1
call FUN_007a4480
add  esp, 10h
```

Both exit arms: restore ExceptionList from `[ebp-0xc]`; **`ret 8`** (`c2 08 00`).

Fail arm: `xor al, al`. Success arm: `cmp esi, ebx` (ebx=0) / `setge al`.

---

## 4. Control flow: clean ≡ raw ≡ live (+ byte fix)

| Stage | Match |
|---|---|
| ESI&lt;0 → fail log (path+hr) | **Yes** (bytes seal hr) |
| VARIANT_BOOL != -1 → parseError dump | **Yes** |
| get_parseError `+0xf0` | **Yes** |
| get_url/reason/line/linepos + free + Release | **Yes** |
| ExceptionList restore both arms | **Yes** |
| ret 8 / bool return | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller LoadDocumentFromPath | **High** | 1 xref |
| Outlined epilogue / parent frame | **High** | no push ebp; ret 8 |
| Fail log includes HRESULT | **High** | `push esi` |
| Dual IDispatch parseError map | **High** | offsets + format string |
| Product symbol | **Open** | may be inline in source |

---

## 6. Gaps / open

1. Original source may not be a separate function (compiler outline).
2. Runtime / differential — open.

**Verdict:** **accept**

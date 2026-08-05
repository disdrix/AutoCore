# Review A (reconstruction fidelity): `aa_0096a630` AssKey_FormatAssIdLogString_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096a630` |
| **VA** | `0x0096a630`–`0x0096a6e1` exclusive (**177 B**) |
| **Canonical name** | `AssKey_FormatAssIdLogString_Inferred` |
| **Ghidra name** | `FUN_0096a630` |
| **Review date** | `2026-08-04` (W38-B dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-B) |
| **Counterpart** | `reviews/B_aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md` |
| **System** | asset / ass-key logging (`client::ass`) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (body + format + null fallback) + `analyze_function_complete` + call-site context |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Format an ass-key's c-string name into a log-facing `std::basic_string`:

```text
// thiscall ECX = key*
// stack   out basic_string*
name = *key; if null → ""
sprintf(buf, "assId: [%s]", name)
*out = buf
return out
```

Evidence string at `0x00aa1c18`: **`assId: [%s]`**. Callers (AssPreloader retire/preload/drain, gfx child load, media helpers) use the result for `vog_LogMessage` / diagnostic lines — not for asset I/O itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096a630_FUN_0096a630.md` (+ W38-B append) |
| Annotated | `docs/reconstruction/raw/aa_0096a630_FUN_0096a630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssKey_FormatAssIdLogString_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096a630.cpp` |
| Function record | `docs/reconstruction/functions/aa_0096a630_FUN_0096a630.md` |
| Named record | `docs/reconstruction/functions/aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md` |
| Live | decompile ≡ raw; body hex 177 B; `RET 4`; format + empty-string ptr confirmed |
| Call sites | `PUSH out; MOV ECX,key; CALL` (e.g. `00970ecb`, `009710c7`, `009714ee`) |
| Context | AssPreloader duals (W32-J / W33-O / W37-B) already cite this as assId formatter |

---

## 3. Signature (sealed)

```c
// thiscall; ECX=key*; stack out basic_string*; RET 4; returns out*
basic_string<char>* __thiscall AssKey_FormatAssIdLogString_Inferred(
    int* key, basic_string<char>* out);
```

| Slot | Source | Conf |
|---|---|---|
| key | **ECX** (`MOV ESI,ECX`) | **High** |
| out | stack formal; cleaned by **`RET 4`** | **High** |
| return | **EAX = out** | **High** |
| SEH | `LAB_009ab872` | **High** |

Decompiler `undefined FUN_0096a630(void)` incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH + local string ctor | **Yes** | **High** |
| `name = *key`; null → `PTR_DAT_00afa2bc` | **Yes** | **High** |
| `sprintf(..., "assId: [%s]", name)` | **Yes** (fmt `0x00aa1c18`) | **High** |
| assign local ← buf; copy-ctor out ← local | **Yes** | **High** |
| dtor local; restore SEH; RET 4 | **Yes** | **High** |
| Product key class English | shape only (`*key` = c-string) | **Inferred** |

Null fallback: dword at `0x00afa2bc` = `0x00a1419b` → first byte `0x00` (empty string).

---

## 5. Gaps / open

1. Product/PDB type name for the key object (wrapper vs raw pointer container).
2. Whether every xref shares first-dword c-string layout (highly likely; not exhaustively audited).
3. SSO/`basic_string` layout bit-exact vs port `std::string`.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

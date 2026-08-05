# Review A (reconstruction fidelity): `aa_00578550` CVOGHBBase_AppendRemainingText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578550` |
| **VA** | `0x00578550`–`0x005786ee` (414 B) |
| **Canonical name** | `CVOGHBBase_AppendRemainingText` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00578550` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-R) |
| **Counterpart** | `reviews/B_aa_00578550_CVOGHBBase_AppendRemainingText.md` |
| **System** | `heartbeat` / timed-actions UI tooltip |
| **Verdict** | **accept-with-gaps** — CF / ABI / gates / unit cascade sealed; quantize leaf formulas residual |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

When `enable` and HB is not in combat-pool sentinel state (`nPeriodCounter != -1000`), format remaining time as localized `"&lt;value&gt; &lt;unit&gt; Remaining\n"` and **append** onto caller dest string. Returns whether text was appended.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00578550_FUN_00578550.md` |
| Named record | `docs/reconstruction/functions/aa_00578550_CVOGHBBase_AppendRemainingText.md` |
| Raw | `docs/reconstruction/raw/aa_00578550_FUN_00578550.md` (+ W23-R live seal) |
| Annotated | `docs/reconstruction/raw/aa_00578550_FUN_00578550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_AppendRemainingText.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00578550.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00578550` |
| Live body | `read_memory` @ entry + epilogue; body end `005786ee` |
| Related dual | `A_aa_00508280_CVOGHBBase_GetRemainingSeconds` |
| Thunk | `FUN_005786f0` → enable fixed to 1 |

**Not performed:** Launcher, runtime golden, bit-exact image diff, full dual of quantize leaves.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **414 B** / end `005786ee` | **Confirmed** | `get_function_by_address` |
| ABI **thiscall** + **`ret 0x10`** | **Confirmed** | epilogue `C2 10 00` |
| Gate enable + `nPeriodCounter!=-1000` | **Confirmed** | bytes `[esp+0x41c]` / `[edi+0x10]` vs `0xFFFFFC18` |
| Remaining via sealed GetRemainingSeconds | **Confirmed** | call + prior dual |
| Thresholds 86400/3600/60 | **Confirmed** | `read_memory` floats |
| Scales 1/86400, 1/3600, 1/60 | **Confirmed** | mulss targets |
| Unit keys days/hrs/min/sec | **Confirmed** | string VAs |
| Format `"%g %s %s\n"` / `"%.0f %s %s\n"` | **Confirmed** | string VAs |
| Append (not replace) dest | **Confirmed** | find dest NUL then copy |
| Return AL 0/1 | **Confirmed** | |
| Two middle stack formals body-dead | **Confirmed** | unused in decomp/bytes |
| Quantize leaf exact math | **Medium** | FUN_00578140 / FUN_00412c60 residual |
| Product / PDB name | **Open** | structural |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| sub esp,0x404 / save ESI EDI | Yes |
| loc ctx FUN_007a69d0 | Yes |
| enable gate | Yes |
| nPeriodCounter==-1000 gate | Yes |
| GetRemainingSeconds | Yes |
| day/hour/min/sec cascade | Yes |
| localize unit + Remaining | Yes |
| sprintf local_400 | Yes |
| strcat onto dest | Yes |
| AL=1 / ret 0x10 | Yes |
| skip path AL=0 | Yes |

---

## 5. Assembly contract (from `read_memory`)

Entry:

```
sub esp, 0x404
push esi / push edi
mov edi, ecx
call FUN_007a69d0 → esi
xor al, al
cmp [esp+0x41c], al     ; enable
jz skip
cmp dword [edi+0x10], -1000
jz skip
```

Epilogue: `mov al,1; pop edi; movzx eax,al; pop esi; add esp,0x404; ret 0x10`

---

## 6. Callers (OWN context)

| Caller | VA | Role |
|---|---|---|
| `FUN_005786f0` | `0x005786f0` | always-enable thunk |
| `FUN_00618c80` / `FUN_00617c10` / `FUN_00621500` | various | tooltip / skill UI builders |
| vtable xref | `0x009d400c` | slot consumer |

---

## 7. Gaps

1. Retail symbol.
2. Product meaning of two unused stack formals.
3. Exact quantize formulas inside `FUN_00412c60` / `FUN_00578140` (not OWN dual targets).
4. Runtime / bit-exact string golden.

**Verdict:** **accept-with-gaps** — unit cascade + ABI + gates sealed; quantize leaves residual.
# Review A (reconstruction fidelity): `aa_0076cec0` Util_VsnprintfToStaticBuf4k

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cec0` |
| **VA** | `0x0076cec0` |
| **Canonical name** | `Util_VsnprintfToStaticBuf4k` (structural) |
| **Ghidra name** | `FUN_0076cec0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0076cec0_Util_VsnprintfToStaticBuf4k.md` |
| **System** | logging / string format (cross-cutting) |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin **printf-into-static-buffer** helper used across auth, graphics asserts, physics factories, terrain, and client error paths.

Body (live decompile ≡ raw ≡ clean):

```c
// FUN_0076cec0(unused_first, format, ...)
_vsnprintf(&DAT_00d19530, 0x1000, format, &va_args);
return &DAT_00d19530;
```

- Destination: global `DAT_00d19530` size **0x1000** (4096).
- Returns pointer to that buffer (not the unused first stack arg).
- First formal is commonly a dummy out pointer at call sites; **bytes never read `[esp+4]`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0076cec0_*`, `reconstructed-exact/FUN_0076cec0.cpp` |
| Function record | `functions/aa_0076cec0_FUN_0076cec0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x0076cec0` (2026-07-29) |
| Bytes | `read_memory` 32 B — `push 0x1000; push &DAT_00d19530; call [_vsnprintf]; mov eax,&DAT_00d19530` |
| Callers (sample) | auth login/trace, `Gfx_SurfaceFormat_AssertUnknownFormat`, phy BV factory, terrain, login callback, many `vog_LogMessage` sites |

### Bytes (head)

```
0076cec0  8B4C2408          mov  ecx, [esp+8]      ; format
0076cec4  8D44240C          lea  eax, [esp+0xC]    ; va_list
0076cec8  50                push eax
0076cec9  51                push ecx
0076ceca  6800100000        push 0x1000
0076cecf  683095D100        push DAT_00d19530
0076ced4  FF15B4649C00      call [_vsnprintf]
0076ceda  83C410            add  esp, 0x10
0076cedd  B83095D100        mov  eax, DAT_00d19530
```

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `_vsnprintf` into `DAT_00d19530` size 0x1000 | **Confirmed** | bytes + decompile |
| Return = `&DAT_00d19530` | **Confirmed** | `mov eax, imm` |
| First stack formal unused | **Confirmed** | no load of `[esp+4]` |
| Thread-safety / reentrancy | **Open** | single global buffer; concurrent use races |
| Product English name | **Open** | no string/RTTI on body |
| clean ≡ raw ≡ live CF | **Confirmed** | three-line function |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| vsnprintf(buf, 0x1000, fmt, va) | Yes |
| return buf | Yes |
| No branches | Yes |

### Recovered CF

```c
char* Util_VsnprintfToStaticBuf4k(/* unused */, const char* fmt, ...) {
  _vsnprintf(g_fmtBuf_d19530, 0x1000, fmt, va_start_after_fmt);
  return g_fmtBuf_d19530;
}
```

Typical parent pattern:

```c
msg = FUN_0076cec0(&scratch, "…%s…", args…);
vog_LogMessage(file, line, level, msg);
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Callee | `_vsnprintf` (IAT) | format |
| Caller | Auth login / message trace | error strings |
| Caller | Graphics / physics assert paths | "Unknown Texture format…", invalid tag |
| Caller | Broad client log sites | shared format buffer |

---

## 6. Gaps / open

1. Product name (likely internal `FormatString` / log helper).
2. Whether any caller relies on first-arg buffer (none in body).
3. Runtime: buffer overwrite if nested calls.

**Verdict:** **accept** — trivial sealed helper; dual complete.

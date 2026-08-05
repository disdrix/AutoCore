# Review B (skeptical / adversarial): `aa_007b6420` Path_GetFileName

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6420` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B, W17-L) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b6420_Path_GetFileName.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Path is stack/`this` arg | Bytes `PUSH EDI`; sites load EDI before CALL | **Falsified** — **EDI** register ABI |
| 2 | Only backslash handled | Second call with `0x2F` | **Falsified** — both |
| 3 | Allocates / copies basename | Returns `ptr+1` into original | **Falsified** — alias |
| 4 | Strips extension | No `strrchr('.', …)` | **Falsified** |
| 5 | When both separators, prefers backslash always | `CMP ESI,EAX` / `JBE` keeps later pointer | **Falsified** — **max pointer** (later in string) |
| 6 | NULL path undefined differently | `strrchr(NULL,…)` is CRT UB — body does not null-check EDI | **Clarify** — callers must pass valid C-string (as CRT) |
| 7 | Dual decompiles disagree | force ≡ decompile | **No conflict** |
| 8 | `__stdcall` RET n | plain `RET` after pop ebx | **Falsified** |
| 9 | IAT not strrchr | slot `0x009c662c`; decompile names strrchr; pcode CALL that slot | **Sealed** as strrchr |
| 10 | Trailing separator returns empty string pointer | `sep+1` may be `""` if path ends with `\`/`/` | **Sealed behavior** — not a bug relative to PathFindFileName |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Basename CF | **High** | Wrong file open paths |
| EDI ABI | **High** | Stack arg port mismatch |
| Dual separators | **High** | Unix-style paths fail |
| Studio name | **Medium** | Rename only |
| NULL path | **N/A** | caller contract |

---

## 3. Cross-check: decompile vs bytes vs pcode

| Step | Decompile | Bytes / pcode |
|---|---|---|
| strrchr `\\` | yes | PUSH 5C / PUSH EDI / CALL IAT |
| strrchr `/` | yes | PUSH 2F / PUSH EDI / CALL IAT |
| no seps | return EDI | MOV EAX,EDI; RET |
| max sep | `sl < bs → bs` | CMP ESI,EAX; JBE keep EAX; else MOV EAX,ESI |
| +1 | `pcVar2+1` | ADD EAX,1 |

**Consensus:** **accept**.

---

## 4. Surviving contract for AutoCore

```csharp
static string PathGetFileNameAlias(string path)
{
    // retail returns interior pointer; managed ports typically allocate a new string
    int i = path.LastIndexOfAny(new[] { '\\', '/' });
    return i < 0 ? path : path.Substring(i + 1);
}
```

**Port traps to reject:**

- Only handling `\`.
- Assuming stdcall/thiscall with stack path.
- Treating trailing-separator empty leaf as error (retail allows `""`).
- Writing a free of the return pointer.

---

## 5. Residual questions

1. Studio symbol / source file (no plate string in body).
2. Whether any caller relies on EDI unchanged (body does not write EDI — preserved).

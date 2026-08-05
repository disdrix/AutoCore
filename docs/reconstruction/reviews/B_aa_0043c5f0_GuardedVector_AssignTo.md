# Review B (skeptical / adversarial): `aa_0043c5f0` GuardedVector_AssignTo

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c5f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0043c5f0_GuardedVector_AssignTo.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory`. No `disassemble_bytes`. Own VA `0x0043c5f0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Plain cdecl, no stack cleanup | Epilogue `C2 04 00` | **Falsified** — **RET 4** |
| 2 | Source is stack arg 0 | Prologue `mov edi,ecx` | **Falsified** — **ECX source** |
| 3 | Always locks | Gate `source+0x2c` | **Falsified** — optional |
| 4 | CS at `+0` / object start | `lea esi,[edi+0x14]` | **Falsified** — **+0x14** |
| 5 | Function creates factories itself | Body only Enter/call/Leave | **Falsified** — assign wrapper |
| 6 | Nested assign is owned here | Only `call FUN_0043c730` | **Survives** as **out of scope** |
| 7 | Name is product English | No plate string | **Survives** — **Inferred** only |
| 8 | live diverges from raw | decompile ≡ raw CF | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX source, stack dest, RET 4 | **High** | Wrong call sites crash |
| CS +0x14 / flag +0x2c | **High** | Deadlock / no lock |
| FUN_0043c730 assign shape | **Probable** | Wrong list contents |
| Product type name | **Inferred** | Naming only |
| Runtime | **Open** | Shipping cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (src+0x2c) EnterCS(src+0x14)
  FUN_0043c730()
  if (src+0x2c) LeaveCS(src+0x14)

bytes:
  8B F9              ; edi = ecx
  80 7F 2C 00        ; cmp [edi+0x2c],0
  8D 77 14           ; esi = &CS
  … EnterCriticalSection
  8B C7              ; eax = source
  8B 7C 24 1C        ; edi = dest
  E8 …               ; FUN_0043c730
  … LeaveCriticalSection
  C2 04 00           ; ret 4
```

**No conflict** on owned CF.

---

## 4. Surviving contract for AutoCore

```csharp
// GuardedVector_AssignTo @ 0x0043c5f0
// retail: ECX=source, stack dest, RET 4

void AssignTo(GuardedVector source, IntPtr dest)
{
    if (source.LockEnable != 0)
        EnterCriticalSection(ref source.Cs); // +0x14
    // FUN_0043c730(EAX=source, EDI=dest) — nested
    VectorAssign(source, dest);
    if (source.LockEnable != 0)
        LeaveCriticalSection(ref source.Cs);
}
```

---

## 5. Verdict

Adversarial review confirms lock wrapper contract. Nested assign and product name residual → **accept-with-gaps**.

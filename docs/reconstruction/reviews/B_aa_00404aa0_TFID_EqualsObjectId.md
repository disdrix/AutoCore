# Review B (skeptical / adversarial): `aa_00404aa0` TFID_EqualsObjectId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404aa0_TFID_EqualsObjectId.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Full 16-byte TFID `memcmp` | Body only loads dword0, dword1, byte+8 | **Falsified** — pad `+9..+15` ignored |
| 2 | `__stdcall` (callee cleans 8 B) | Epilogue is plain `RET` | **Falsified** — **`__cdecl`** |
| 3 | Returns bool-as-char only | `MOV EAX,1` / `XOR EAX,EAX` full int | **Over-narrow** — returns **int** 0/1 (usable as bool) |
| 4 | Null-safe | No test on pA/pB before deref | **Falsified if claimed safe** — null → fault |
| 5 | Compares “object pointer identity” | Args are **pointers into id blocks**, not object* equality | **Clarify** — value equality of TFID fields, not pointer-equal of objects |
| 6 | Name `EqualsObjectId` means full game Object | Only 3 id fields; no vtable/type/map string | **Accept name as TFID ObjectId**, not full CVOGObject |
| 7 | Different from `TFID_NotEquals` math | Sibling same compares, inverted returns | **Complement only** — same equality kernel |
| 8 | Invalid TFID needs special case in body | Invalid is data `{-1,-1,0,...}`; callers pass sentinel | **No special case** in this unit |
| 9 | Incomplete decompiler (missed fields) | Bytes match decompile field-for-field | **No missed compare** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0/1 returns on three-field match | **High** | Identity bugs across skill/cast/collision |
| Only +0/+4/+8 | **High** | Over-strict equality if pads matter on wire |
| cdecl | **High** | Wrong call ABI on ports |
| No null check | **High** | Defensive ports must not invent checks if matching retail faults |
| Field product names | **Medium** | Doc naming only |
| “ObjectId” == TFID_16 head | **High** for callers that pack `obj+0x160` | Mis-wiring other id layouts |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  *(int*)pA == *(int*)pB
  && *(int*)(pA+4) == *(int*)(pB+4)
  && *(char*)(pA+8) == *(char*)(pB+8)
  → 1 else 0

bytes:
  CMP [pA+0],[pB+0] / [pA+4],[pB+4] / [pA+8],[pB+8]
  MOV EAX,1 / XOR EAX,EAX ; RET
```

Clean scaffold must not invent `memcmp(16)`, type tags beyond byte+8, or null guards.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact identity for ObjectId / TFID head (not full 16B memcmp)
static int TFID_EqualsObjectId(ref Tfid a, ref Tfid b)
{
    // retail: no null check — ports may still assert in debug
    if (a.CoidLo != b.CoidLo) return 0;
    if (a.CoidHi != b.CoidHi) return 0;
    if (a.BGlobal != b.BGlobal) return 0; // byte at +8
    return 1;
    // do NOT compare pad[9..15]
}

// Invalid check pattern used by many callers:
// TFID_EqualsObjectId(&tfid, &g_abTfidInvalid) where invalid = (-1,-1,0)
```

**Port traps to reject:**

- Implementing as `SequenceEqual` of 16 bytes.
- Treating return as pointer / object*.
- Using `__stdcall` / `thiscall`.
- Assuming equality implies same sector map / same ghost index beyond these fields.

---

## 5. Residual gaps (do not block seal)

1. Product English for `bGlobal` (global vs local object id bit).
2. Whether any path zero-extends char compare differently (body is byte CMP — signedness irrelevant for equality).
3. Exhaustive caller-site argument provenance (parent residual).
4. Runtime live hit / bit-exact image.

---

## Verdict

**accept** — adversarial review cannot break the three-field equality kernel. Main falsification is “full TFID_16 memcmp”; main caution is null-deref and pad-ignore semantics for ports.

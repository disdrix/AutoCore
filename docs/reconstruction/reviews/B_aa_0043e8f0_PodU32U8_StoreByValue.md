# Review B (skeptical / adversarial): `aa_0043e8f0` PodU32U8_StoreByValue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e8f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-M) |
| **Counterpart** | `reviews/A_aa_0043e8f0_PodU32U8_StoreByValue.md` |
| **Scratch** | `docs/reconstruction/tmp/a_0043e8f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void()` / no formals is complete | **Falsified** — ESI dest + 2 stack values + EAX return; callers `ADD ESP,8` |
| 2 | Same as `PodU32U8_StoreSplit` | **Falsified** — this is by-value adapter; nested is pointer StoreSplit with `RET 4` |
| 3 | Same as `PodU32U8_CopyIfNonNull` | **Falsified** — no null gate; sources are stack values not contiguous POD*; ESI not EAX dest at entry |
| 4 | stdcall `RET 8` | **Falsified** — bare `C3`; cleanup is caller's `ADD ESP,8` |
| 5 | Contiguous POD* in ECX | **Falsified** — ECX is LEA of stack u32 only after push |
| 6 | Product name retail | **Overstated** — inferred structural |
| 7 | Body grows container | **Falsified** — 19 B store adapter only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI dest + stack by-value + bare RET + EAX return | **High** | Wrong ABI in port |
| Nested only `0043ea50` | **High** | Missed side effects |
| No null gate | **High** | Missed crash if dest null |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Parent rings free |

---

## 3. Cross-check against raw + bytes

```
raw plate:  FUN_0043ea50(&stack0x00000008); return;
live list:  LEA/PUSH &+8; LEA ECX,&+8'; MOV EAX,ESI; CALL 0043ea50; MOV EAX,ESI; RET
hex:        8D442408 50 8D4C2408 8BC6 E850010000 8BC6 C3
caller:     … CALL 0043e8f0; ADD ESP,8; PUSH EAX; CALL 0043e7f0 …
```

Contrast matrix:

| Unit | Null? | Sources | Dest | RET |
|---|---|---|---|---|
| `0043ece0` | yes | contiguous u32×2 | EAX | bare |
| `0043ecf0` | yes | contiguous u32+u8 | EAX | bare |
| `0043ea50` | no | split u32* + u8* | EAX | 4 |
| **`0043e8f0`** | no | **by-value** stack | **ESI** | bare (cdecl) |

---

## 4. Surviving contract for AutoCore

```
// PodU32U8_StoreByValue:
//   ESI = dest; stack u32, u8; bare RET; returns dest
//   adapts to PodU32U8_StoreSplit (do not substitute CopyIfNonNull)
//   callers must clean 8 bytes
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/nested leaf/write path; product residual only → **accept**.

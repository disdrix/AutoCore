# Review B (skeptical / adversarial): `aa_004a68d0` BasicStringW_CopyBackward_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a68d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-T) |
| **Counterpart** | `reviews/A_aa_004a68d0_BasicStringW_CopyBackward_0x1c.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Forward `std::copy` | **Falsified** — `SUB ESI/EDI, 0x1C` before each assign; stop when `last==first` |
| 2 | POD `memmove` / dword copy | **Falsified** — IAT wstring assign; not raw memcpy |
| 3 | Uninitialized construct | **Falsified** — `operator=` on existing slots only |
| 4 | thiscall / member | **Falsified** — plain cdecl; three stack formals; ECX only for nested assign |
| 5 | Void / discarded return | **Weakened at body** — body returns EAX final dest; parent may discard (post-call uses fill with other regs) |
| 6 | Char string not wstring | **Falsified** — parent `InsertN_BasicStringW`; IAT `[0x009c63bc]` |
| 7 | Product plate retail | **Overstated** — structural `_Inferred` name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reverse assign + stride 0x1c | **High** | Mid-insert corruption |
| cdecl 3-arg plain RET | **High** | Stack imbalance |
| IAT operator= identity | **High** | Wrong string semantics |
| EAX return value | **High** | Port drops return if needed |
| Product English | **Inferred** | Naming only |
| Runtime golden | **Open** | Overlap edge cases |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (first == last) return dest_end;
  do { last-=0x1c; dest_end-=0x1c; operator=(dest_end, last); }
  while (last != first);
  return dest_end;

bytes:
  CMP EBX,ESI / JE empty
  SUB ESI,1C; SUB EDI,1C; PUSH ESI; MOV ECX,EDI; CALL [IAT]; CMP ESI,EBX / JNE
  MOV EAX,EDI; RET
  empty: MOV EAX,[ESP+14]; RET
```

Sole caller `FUN_004a7ad0` @ `0x004a7dbf` then fill `004a68a0` — classic insert mid path (shift tail back, fill hole). Live decompile ≡ raw. Body 51 B ≡ char twin.

---

## 4. Surviving contract for AutoCore

```
// BasicStringW_CopyBackward_0x1c(first, last, dest_end):
//   copy_backward [first, last) into ending at dest_end
//   stride 0x1c; per-element basic_string<wchar_t>::operator=
//   cdecl; returns final dest pointer
// Mid-insert MUST reverse-walk (not forward) for overlap safety.
// Do not substitute POD memmove, forward copy, or char twin.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/stride/IAT; rejects forward/POD/uninit/char misreads → **accept**.

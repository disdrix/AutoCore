# Review B (skeptical / adversarial): `aa_00431790` BasicString_CopyBackward_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431790` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-L) |
| **Counterpart** | `reviews/A_aa_00431790_BasicString_CopyBackward_0x1c.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a thunk | **Falsified** — 51 B reverse loop + IAT `operator=`; thunk is parent `00431480` |
| 2 | Forward `std::copy` | **Falsified** — `SUB ESI/EDI, 0x1C` before each assign; stop when `last==first` |
| 3 | POD `memmove` / dword copy | **Falsified** — IAT string assign; not raw memcpy |
| 4 | Uninitialized construct | **Falsified** — `operator=` on existing slots only |
| 5 | thiscall / member | **Falsified** — plain cdecl; no ECX use; three stack formals |
| 6 | Void / discarded return | **Weakened at body** — body returns EAX final dest; sole caller discards it (parent contract void) |
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

Sole caller `00431480` reorders into this free helper (W33-I sealed). Live decompile 2026-07-29 ≡ raw 2026-07-23.

---

## 4. Surviving contract for AutoCore

```
// BasicString_CopyBackward_0x1c(first, last, dest_end):
//   copy_backward [first, last) into ending at dest_end
//   stride 0x1c; per-element basic_string::operator=
//   cdecl; returns final dest pointer
// Mid-insert MUST reverse-walk (not forward) for overlap safety.
// Do not substitute POD memmove or uninitialized fill.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/stride/IAT; rejects thunk/forward/POD misreads → **accept**.

# Review B (skeptical / adversarial): `aa_0076bc00` Fs_CreateDirectoryForce_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076bc00` |
| **VA** | `0x0076bc00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0076bc00_Fs_CreateDirectoryForce_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 121 B + 4 callers + peer FS duals |
| **Agent** | W37-Z OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Bit 15 is `S_IFDIR` | CRT `_S_IFDIR=0x4000` (bit 14); `_S_IFREG=0x8000` (bit 15); is-dir already handled by `FUN_0076adc0` | **Falsified dir-bit** — sealed as regular file |
| 2 | Always deletes before create | Force gate; non-force falls to CreateDirectoryA only | **Falsified always-delete** |
| 3 | thiscall / ECX path | Callers `PUSH; PUSH; CALL; ADD ESP,8` | **Falsified thiscall** |
| 4 | Returns void / HRESULT | `SETNZ AL` after CreateDirectoryA | **Falsified void** — bool AL |
| 5 | NDRenderEngine product name | FS utility; CompactPackFile consumer | **Rejected scaffold** |
| 6 | `FUN_0076b080` path is stack formal | Peer DeleteDirTree: ESI=path; this unit only pushes force `1` | **Sealed ESI path** |
| 7 | Product name sealed | Structural `_Inferred` only | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Create-dir + force clear role | **Confirmed** | Wrong pack path setup |
| cdecl path+force; bool AL | **Confirmed** | Caller contract break |
| Dir wipe vs file unlink split | **Confirmed** | Data loss / wrong path |
| `_S_IFREG` gate | **Confirmed** | Wrong file detect |
| Product name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

| Caller | Pattern |
|---|---|
| `FUN_00985010` CompactPackFile | `PUSH 1; PUSH path; CALL; ADD ESP,8` — force recreate `_pk_` |
| `FUN_007a13e0` | force=`1` |
| `FUN_0076bc80` | sibling; tests AL after call |
| `FUN_004b52e0` | path build then call |

Peers W33-C / W34-A already sealed is-dir and recursive delete used here.

---

## 4. Byte anchors

```text
0x0076bc00: 83 EC 24 80 7C 24 2C 00   ; frame; cmp force
            56 8B 74 24 2C …          ; ESI=path
            E8 … FUN_0076adc0
            6A 01 56 E8 … FUN_0076ba10
            FF 15 … CreateDirectoryA
            0F 95 C0 … C3             ; SETNZ; RET
            … stat …
            C1 E9 0F 80 E1 01         ; st_mode >> 15 & 1
            6A 01 E8 … FUN_0076b080
            … CreateDirectoryA; SETNZ; RET
```

---

## 5. What would reverse the seal?

- Proof bit 15 is directory — contradicted by CRT constants and separate is-dir call.
- Proof stdcall / RET 8 — contradicted by caller `ADD ESP,8` and bare `C3`.
- Proof no force path — contradicted by early cmp and dual wipe/unlink arms.

None observed.

**Verdict:** **accept**

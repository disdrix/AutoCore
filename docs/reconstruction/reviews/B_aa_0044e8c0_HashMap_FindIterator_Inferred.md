# Review B (skeptical / adversarial): `aa_0044e8c0` HashMap_FindIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e8c0` |
| **VA** | `0x0044e8c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0044e8c0_HashMap_FindIterator_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` + 20 xrefs + hash leaf + cache caller dual |
| **Agent** | W21-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `unaff_EDI`/`unaff_EBX` are decompiler junk | All map fields via EDI; key via EBX; callers set both | **Falsified junk** — sealed formals |
| 2 | Pure `__stdcall` with map/key on stack | Only one stack arg; `ret 4`; EDI/EBX live | **Falsified pure stdcall** |
| 3 | Unordered full-bucket scan | Greater-key path returns end without scanning rest | **Falsified unordered-only** |
| 4 | Equality is `strcmp` | Body compares dwords `*key` vs `node+8` only | **Falsified strcmp-in-body** |
| 5 | This inserts or creates on miss | Only writes end sentinel; no alloc | **Falsified insert** |
| 6 | Same as `CNDHash_LookupByKey` (`0x005b0920`) | Different VA, layout, ABI family | **Falsified conflation** |
| 7 | Bucket pairs are 8-byte entries indexed `*8` | Index `*4` with `start`/`start+4` as end | **Adjacent-slot end sealed** |
| 8 | Product name sealed | Role-inferred from CF + callers | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Find CF + miss/hit writes | **Confirmed** | Wrong cache lookup |
| Register+stack ABI | **Confirmed** | Caller contract break |
| Offsets | **Confirmed** | Map layout ports |
| Product class name | **Open** | Doc-only |
| Key domain semantics | **Open** | Wrong key prep in ports |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

`NDResourceCache_LookupOrCreate` owns create/factory policy after miss (`it == cache+0x08`). This unit owns **only** hash find + iterator write. Do not merge insert (`FUN_0043c6f0` family) into this dual.

---

## 4. Byte anchors

```text
0x0044e8c0: 51 55 8B 6C 24 0C 56
            8B 77 20 8B C3 E8 …   ; mask; EAX=key; hash
            23 C6 39 47 24 77 09  ; & mask; fold if needed
            8B 57 14 8D 0C 82     ; table + idx*4
            8B 01 3B 41 04 …      ; start vs end
            8B 13 39 50 08 …      ; *key vs node+8
            … C2 04 00            ; all three epilogues
```

---

## 5. What would reverse the seal?

- Proof callers pass map/key on stack instead of EDI/EBX (would reclassify ABI) — contradicted by body + cache caller dual prologue.
- Proof bucket end is not `table[idx+1]` (would reclassify geometry) — body uses `[ecx+4]` after `lea ecx,[table+idx*4]`.

None observed from decompile + bytes + leaf + callers.

# Review B (skeptical / adversarial): `aa_0040afb0` Host_LookupObjectByKey_PairTable30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040afb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-028 OWN dual B) |
| **Counterpart** | `reviews/A_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/layout; product English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function is soft-cast-only hit-table API | 13 sites across area/collision/UI; body has no cast/ray math | **Falsified as exclusive** — shared leaf |
| 2 | Returns object\* in EAX directly | Bytes store to `*out`; EAX = out pointer; callers deref `[eax]` | **Falsified** — out-param idiom |
| 3 | `cdecl` / `RET 4` / one stack arg | `RET 8` both exits; two stack formals | **Falsified** |
| 4 | Table is std::map / tree / hash | Linear scan; no callees; stride-8 array | **Falsified** |
| 5 | Count is at +0x30 and base at +0x34 | Bytes: `mov edx,[ecx+0x34]` then `mov esi,[ecx+0x30]` | **Falsified** — base@30 count@34 |
| 6 | Value is at pair+0 (key at +4) | Hit path `mov ecx,[esi+eax*8+4]` | **Falsified** — key@0 value@4 |
| 7 | Scaffold name (VOG_DEBUG_STOP callee) is product | String `"VOG_DEBUG_STOP"` lives in `FUN_004ea350` failure path; this VA never references it | **Falsified** — scaffold retired |
| 8 | Decompiler `void` means no return value | EAX loaded with out before both RETs | **Survives as EAX=out** |
| 9 | Writes/mutates host table | Body only loads host fields; stores only to `*out` | **Falsified as mutator** |
| 10 | Key is always 1 | Sites push 3 and 4 in collision prep | **Falsified as key=1 only** |
| 11 | This is TFID / entity resolve by id | Keys are small ints 1/3/4; no TFID_16 width | **Falsified** |
| 12 | Partition "soft-cast hit table" means body owns cast | Body is generic pair lookup; soft-cast is a caller | **Survives as caller role only** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x30/+0x34 / stride 8 / RET 8 | **High** | Wrong host layout port |
| Out-param object\* role | **High** | Wrong return wiring |
| Multi-key (1/3/4) | **High** | Miss material FX path |
| Product host type name | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0040afb0  mov  edx, [ecx+0x34]        ; count
0040afb3  push esi
0040afb4  xor  eax, eax               ; i
0040afb6  test edx, edx
0040afb8  push edi
0040afb9  jle  miss
0040afbb  mov  esi, [ecx+0x30]        ; table
0040afbe  mov  edi, [esp+0x10]        ; key
... loop cmp [ecx],edi / add ecx,8 ...
miss:  mov [out], 0 ; ret 8
hit:   mov ecx, [esi+eax*8+4] ; mov [out], ecx ; ret 8
```

Live 2026-08-05 ≡ 2026-07-23 raw decompile CF.

---

## 4. Surviving contract for AutoCore

```text
void** out;
Host_LookupObjectByKey_PairTable30(host, &outSlot, key);
// or: object = *Host_LookupObjectByKey_PairTable30(host, &outSlot, key);
// host has pairs@+0x30, count@+0x34; pair = {int key; void* value}
// first match; miss → NULL; no mutation of host
```

Do **not** implement as soft-cast ray, TFID resolve, map tree, or VOG_DEBUG helper.

**Verdict:** **accept-with-gaps**.

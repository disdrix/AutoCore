# Review A (reconstruction fidelity): `aa_00419ad0` CNDHash_BucketChainTouchRepair

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ad0` |
| **VA** | `0x00419ad0` |
| **Body** | `0x00419ad0`–`0x00419b30` exclusive (**96** B) |
| **Canonical name** | `CNDHash_BucketChainTouchRepair` |
| **Prior / alias** | `FUN_00419ad0`; `Util_HashListError_Repair` (registry/plate) |
| **Review date** | `2026-07-29` (W19-D OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| **System** | container / CNDHash u64-bucket integrity |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Integrity walk + optional cycle repair** on a CNDHash **bucket** chain:

1. Head `*(bucket+4)==0` → return.
2. Walk: mark `*(node+8)=1`; advance `*(node+0x10)`.
3. Null next → clear all marks (healthy).
4. Next already marked → log severity 1 `"HashListError: Went to node we already touched! Attempting repair!"` @ `0x00a64710` via `FUN_007a4480`; sever `*(prev+0x10)=0`; clear marks.

No free / no key compare / no ordered-list splice. Unconditional after insert/unlink in this family.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00419ad0_FUN_00419ad0.md` (+ W19-D append) |
| Annotated | `docs/reconstruction/raw/aa_00419ad0_FUN_00419ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_BucketChainTouchRepair.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00419ad0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| Live decompile | ≡ raw (EDI, +8/+0x10) |
| Live body bytes | `read_memory` @ `0x00419ad0` length 128 |
| String | `read_memory` @ `0x00a64710` full message |
| Sibling dual | `aa_00419b80` BucketUnlink always calls this (EDI=bucket) |
| Clone dual | `aa_00537d30` different offsets (not this VA) |

---

## 3. Byte seal (`read_memory` @ `0x00419ad0`)

```
8b 47 04          mov eax, [edi+4]      ; head
53                push ebx
33 db             xor ebx, ebx
3b c3             cmp eax, ebx
74 55             je empty_ret
b9 01 00 00 00    mov ecx, 1
56                push esi
88 48 08          mov [eax+8], cl       ; touch = 1
8b f0             mov esi, eax          ; prev
8b 40 10          mov eax, [eax+0x10]   ; next
…
68 10 47 a6 00    push 0x00a64710       ; string
51                push ecx              ; severity 1
e8 …              call FUN_007a4480
89 5e 10          mov [esi+0x10], ebx   ; sever next=0
…
c3                ret
```

| Claim | Evidence | Conf |
|---|---|---|
| EDI = bucket (head load `[edi+4]`) | `8b 47 04` + insert call-site sets EDI | **High** |
| Touch `node+8` | `88 48 08` / `38 58 08` / clear `88 58 08` | **High** |
| Next `node+0x10` | `8b 40 10` / sever `89 5e 10` | **High** |
| String imm `0x00a64710` | `68 10 47 a6 00` + `read_memory` text | **High** |
| Bare `ret` | final `c3` (not `c2 xx`) | **High** |
| Body span 96 B | meta exclusive end `00419b30` | **High** |
| Decompile ≡ raw ≡ bytes intent | three-rep match | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Empty head early return | **Yes** |
| Mark walk + healthy clear | **Yes** |
| Cycle: log + sever + clear | **Yes** |
| No invented free/key/ordered-list | **Yes** |
| EDI ABI (not ECX-thiscall) | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| u64 CNDHash node layout (+8/+0x10) | **High** | matches BucketUnlink dual |
| Always-on integrity (not debug-only) | **High** | 4 unconditional callers |
| Product English spelling | **Low–Med** | plate/registry open |
| Severed-node lifetime | **Med** | no free here |

---

## 6. Gaps

1. Product/PDB symbol.
2. Whether severed tails are later freed by another path.
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept** — ABI, layout, CF, string sealed; product name residual only.

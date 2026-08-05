# Review A (reconstruction fidelity): `aa_00449dc0` phyBoneSharedData_CreateDefaultAndInstall

| Field | Value |
|---|---|
| **Stable ID** | `aa_00449dc0` |
| **VA** | `0x00449dc0` |
| **Body** | `0x00449dc0`–`0x00449e72` exclusive (**178** B) |
| **Canonical name** | `phyBoneSharedData_CreateDefaultAndInstall` |
| **Prior / alias** | `FUN_00449dc0`; residual `Named_CalleeOf_Named_gfxBodyMassageMachine_00449dc0` |
| **Review date** | `2026-07-29` (W20-E OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| **System** | physics / phy (asset I/O) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Create + install default phyBoneSharedData** into RefCounted slot `*(EBX+4)`:

1. `operator_new(0x90)` (null-safe).
2. Init identity hkQsTransform + identity bind matrix + null collision slot; vtbl `PTR_FUN_00aa050c`.
3. AddRef; if first ref call empty `vtbl+4`.
4. Release old `*(EBX+4)` via refcount/`vtbl+8`.
5. Store new at `*(EBX+4)`.

Callers always `LEA EBX,[bone+0xf0]` → slot is **`bone+0xf4`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00449dc0_FUN_00449dc0.md` (+ W20-E append) |
| Annotated | `docs/reconstruction/raw/aa_00449dc0_FUN_00449dc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBoneSharedData_CreateDefaultAndInstall.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00449dc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| Live decompile | ≡ raw (EBX slot, 0x90, identity defaults) |
| Live body bytes | `read_memory` @ `0x00449dc0` length 200 |
| Globals | `g_flOne` `00 00 80 3f`; identity matrix `DAT_00afdf70`; vtbl `00aa050c` |
| Parent dual | `aa_0096e280` phyBone_unserialize (calls this then BDAT then `0096de80`) |

---

## 3. Byte seal (`read_memory` @ `0x00449dc0`)

```
56                push esi
68 90 00 00 00    push 0x90
e8 …              call operator_new
83 c4 04          add esp, 4
85 c0             test eax, eax
74 72             je null_path
0f 57 c0          xorps xmm0, xmm0
f3 0f 10 0d a0 f2 a0 00  movss xmm1, [g_flOne]
c7 40 04 00 00 00 00     mov [eax+4], 0
c7 00 0c 05 aa 00        mov [eax], PTR_FUN_00aa050c
…
8d 78 40          lea edi, [eax+0x40]
b9 10 00 00 00    mov ecx, 0x10
be 70 df af 00    mov esi, DAT_00afdf70
f3 a5             rep movsd
c7 80 80 00 00 00 00 00 00 00  mov [eax+0x80], 0
…
83 46 04 01       add [esi+4], 1          ; AddRef
…
8b 4b 04          mov ecx, [ebx+4]        ; old slot
…
89 73 04          mov [ebx+4], esi        ; install
5e                pop esi
c3                ret
```

| Claim | Evidence | Conf |
|---|---|---|
| Size 0x90 | `68 90 00 00 00` | **High** |
| vtbl imm `0x00aa050c` | `c7 00 0c 05 aa 00` | **High** |
| g_flOne load | `movss` from `0x00a0f2a0` + bytes `00 00 80 3f` | **High** |
| Matrix copy 16 dwords @ +0x40 | `lea edi,[eax+40]` / `ecx=10` / `rep movsd` from `00afdf70` | **High** |
| Collision slot +0x80 = 0 | `c7 80 80 00 00 00 00…` | **High** |
| EBX+4 install | `8b 4b 04` / `89 73 04` | **High** |
| Bare `ret` | final `c3` | **High** |
| Body 178 B | exclusive end `00449e72` | **High** |
| Decompile ≡ raw ≡ bytes intent | three-rep match | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| new(0x90) + null branch | **Yes** |
| Identity qs + matrix + +0x80=0 | **Yes** |
| AddRef + first-ref virtual | **Yes** |
| Release old + store | **Yes** |
| EBX ABI (not ECX-thiscall) | **Yes** |
| No invented args / free of new on fail | **Yes** (null install allowed) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| Slot = bone+0xf4 via call sites | **High** | all 5 LEA EBX,[reg+0xf0] |
| Object is shared-data for BDAT | **High** | parent plate + unserialize uses +0xf4 |
| Product ctor English | **Low–Med** | structural name from role |
| Runtime / bit-exact | Open | static dual only |

**Verdict:** **accept** — create/install CF + ABI + layout sealed.

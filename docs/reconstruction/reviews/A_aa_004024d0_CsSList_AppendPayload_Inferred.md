# Review A (reconstruction fidelity): `aa_004024d0` CsSList_AppendPayload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004024d0` |
| **VA** | `0x004024d0`–`0x0040258a` |
| **Canonical name** | `CsSList_AppendPayload_Inferred` |
| **Ghidra name** | `FUN_004024d0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual W18-B) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004024d0_CsSList_AppendPayload_Inferred.md` |
| **System** | client containers / deferred-queue append |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

CS-protected **singly-linked tail append** of a payload pointer: allocate `0xC` node (`PTR_FUN_009cb340`), link at tail under critical section(s), then **InterlockedIncrement** count after unlock.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x004024d0` — ≡ 2026-07-23 raw |
| Live epilogue | `decompile_function` @ `0x00402598` — Leave CS + InterlockedIncrement |
| Raw | `docs/reconstruction/raw/aa_004024d0_FUN_004024d0.md` (+ residual seal) |
| Annotated | `docs/reconstruction/raw/aa_004024d0_FUN_004024d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CsSList_AppendPayload_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004024d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004024d0_CsSList_AppendPayload_Inferred.md` |
| Live bytes | `read_memory` 200 B @ `0x004024d0` — `ret 4`, node vtbl imm, CS offs |
| Parent dual | `Object_EnqueueDeferredOnce` (`aa_004d0e90`) treats this as ListAppend |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff, product PDB.

---

## 3. Byte seal (key claims)

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in **ECX** → ESI | **High** | `8B F1` |
| Stack payload `[ebp+8]` | **High** | `8B 5D 08` |
| Null payload → AL=0, **`ret 4`** | **High** | `32 C0` … `C2 04 00` |
| `operator_new(0xC)` | **High** | `6A 0C` + call |
| Node vtbl **`0x009CB340`** | **High** | `C7 00 40 B3 9C 00` |
| Node payload `+4`, next `+8` | **High** | stores; link writes `+8` |
| Outer CS if **count ≤ 3** at `+0xC` | **High** | `83 7E 0C 03` / `7F` skip; `lea [esi+0x28]` |
| Always CS at **`+0x10`** | **High** | `lea [esi+0x10]` Enter |
| Head `+4` / tail `+8` | **High** | empty and link paths |
| Unlock + count via `FUN_00402598` | **High** | decompile: Leave + `InterlockedIncrement(+0xC)` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null early-out | **Yes** |
| Alloc + vtbl init | **Yes** |
| Optional outer CS + primary CS | **Yes** |
| Empty vs non-empty tail link | **Yes** |
| Shared unlock/increment epilogue | **Yes** |
| No modernization | **Yes** |

---

## 5. Confidence summary

| Dimension | Level |
|---|---|
| Function boundary + ABI | **High / Sealed** |
| Tail-append structure | **High / Sealed** |
| Dual-CS policy (count ≤ 3) | **High / Sealed** |
| Role = ListAppend for deferred queues | **High** (parent duals) |
| Product class / vtbl English | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 6. Gaps

1. Product C++ name for list/node (`PTR_FUN_009cb340` methods).
2. Rationale for outer CS only when `count ≤ 3`.
3. Null-`operator_new` crash vs guarded (raw stores through node without null check after assign).
4. Full consumer/free path for nodes.
5. Runtime / differential verification.

**Verdict:** CF + ABI + layout sealed from live decompile + `read_memory`. Product names inferred. **accept-with-gaps.**

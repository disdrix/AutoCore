# Review A (reconstruction fidelity): `aa_004d0e90` Object_EnqueueDeferredOnce

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0e90` |
| **VA** | `0x004d0e90` |
| **Canonical name** | `Object_EnqueueDeferredOnce` (was `FUN_004d0e90`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_004d0e90_Object_EnqueueDeferredOnce.md` |
| **System** | client world / reaction lifecycle |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** — **bit0 sticky queue + `this+0xe5fc` sealed** |

---

## 1. Purpose

**Idempotent deferred enqueue.** Given reaction/world **host** in ECX and **object** on the stack: if the object is not already marked/queued, append it to the CS-protected list at `host+0xe5fc` and set **`ObjectFlag_DeferredQueued`** (`object+0x17c` bit **0**, mask **`0x1`**).

| Slot | Role | Evidence |
|------|------|----------|
| `this` / ECX | host with queue `@+0xe5fc` | `mov edi, ecx`; `mov ecx, [edi+0xe5fc]` |
| stack arg | `Object*` | `mov esi, [esp+8]`; `test/or [esi+0x17c]` |
| epilogue | `ret 4` | `c2 04 00` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d0e90_FUN_004d0e90.md` |
| Annotated | `docs/reconstruction/raw/aa_004d0e90_FUN_004d0e90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EnqueueDeferredOnce.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004d0e90.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d0e90_FUN_004d0e90.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x004d0e90` — surface ≡ 2026-07-23 raw |
| Live bytes | Ghidra `read_memory` 64 B — ends `c2 04 00` + `CC` |
| Callee contains | `FUN_004e15a0` @ `0x004e15a0` (decompile) |
| Callee append | `FUN_004024d0` @ `0x004024d0` (decompile) |
| Parent use | `CVOGReaction_RemoveObject` dual (alive short path) |

**Not performed:** `disassemble_bytes` (policy), Launcher, live CE, bit-exact image diff, full queue-consumer RE.

---

## 3. Control flow: live surface vs bytes

| Stage | Decompiler surface | Bytes |
|---|---|---|
| Load object from stack | param_1 only | **Yes** `mov esi,[esp+8]` |
| Capture ECX host | **Missing** | **Yes** `mov edi,ecx` |
| Test bit0 `@obj+0x17c` | **Yes** | **Yes** `test byte [esi+0x17c],1` |
| Load queue `@host+0xe5fc` | **Missing** (collapsed) | **Yes** `mov ecx,[edi+0xe5fc]` |
| Contains check | `FUN_004e15a0(param_1)` | **Yes** thiscall queue + push obj |
| Append | `FUN_004024d0(param_1)` | **Yes** thiscall queue + push obj |
| OR bit0 | **Yes** | **Yes** `or dword [esi+0x17c],1` |
| `ret 4` | implicit void | **Yes** `c2 04 00` |

### Closed form (sealed)

```text
// ECX = Host*; stack = Object*
if ((flags[obj+0x17c] & 1) != 0) return;
q = *(Host+0xe5fc);
if (ListContains(q, obj)) return;     // FUN_004e15a0
ListAppend(q, obj);                   // FUN_004024d0
flags[obj+0x17c] |= 1;                // ObjectFlag_DeferredQueued
```

### Mask **`0x1` / bit 0** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `*(byte*)(obj+0x17c) & 1` and final `\| 1` |
| Bytes | `f6 86 7c 01 00 00 01` ; `83 8e 7c 01 00 00 01` |
| Role | sticky “already deferred-queued” gate |

### Field **`host+0xe5fc`** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Bytes | `8b 8f fc e5 00 00` twice (before both callees) |
| Callee this | ECX loaded from that field for contains/append |

---

## 4. Confidence

| Dimension | Level |
|---|---|
| Function boundary (`004d0e90`–`004d0ec8`, `ret 4`) | **High / Sealed** |
| ECX host + 1 stack object | **High / Sealed** |
| Bit0 sticky OR | **High / Sealed** |
| Queue at `+0xe5fc` | **High / Sealed** |
| Role = deferred enqueue once | **High** |
| Product class names (queue/node) | **Tentative** |
| Consumer / clear-bit policy | **Open** |

---

## 5. Gaps

1. Who drains the `+0xe5fc` list and when bit0 clears.
2. Full English name of list node vtbl `PTR_FUN_009cb340`.
3. Whether all ~20 callers pass the same host type.
4. Original PDB symbol.
5. Runtime / bit-exact verification.

**Verdict:** CF + ABI + bit0 + queue field sealed. **accept-with-gaps.**

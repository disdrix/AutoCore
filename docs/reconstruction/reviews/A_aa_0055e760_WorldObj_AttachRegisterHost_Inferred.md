# Review A (reconstruction fidelity): `aa_0055e760` WorldObj_AttachRegisterHost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e760` |
| **VA** | `0x0055e760`–`0x0055e850` |
| **Body** | **240 bytes** (`0xF0`) |
| **Canonical name** | `WorldObj_AttachRegisterHost_Inferred` |
| **Ghidra name** | `FUN_0055e760` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-T) |
| **Counterpart** | `reviews/B_aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` |
| **System** | world-object / phys host attach |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs + `get_assembly_context` |
| **Verdict** | **accept** |

---

## 1. Purpose

Manager **thiscall** attach/register of world object onto a host:

1. `obj+8 = manager`.
2. If sticky `obj+0x40`: `Host_Attach(*(manager+0x2c), obj)`.
3. If `manager+0x23c`: alloc/init 0xa8 host (tag `0x2d`), attach, push on `manager+8`.
4. Else if no hosts: create first host; attach to `list[0]`.
5. Else: attach to existing first host.

Paired with `WorldObj_BindLinks_Inferred` at enroll/reattach/rehome call sites.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055e760_FUN_0055e760.md` (+ 2026-07-29 W29-T append) |
| Annotated | `docs/reconstruction/raw/aa_0055e760_FUN_0055e760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_AttachRegisterHost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055e760.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055e760_FUN_0055e760.md` |
| Named record | `docs/reconstruction/functions/aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` |
| Live | decompile ≡ raw stages; prologue/epilogue bytes; **machine host this** |
| Call sites | enroll / reattach / rehome: `PUSH obj; MOV ECX,mgr; CALL` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of nested `006291e0` / `006295f0` / arena.

---

## 3. Signature (sealed)

```c
// thiscall; ECX = manager; stack obj; ret 4; void
void WorldObj_AttachRegisterHost_Inferred(int manager /*ECX*/, uint32_t obj);
```

| Formal | Source | Conf |
|---|---|---|
| manager | ECX (`MOV ESI,ECX`) | **High** |
| obj | `[esp+8]` after push EBP (`MOV EBP,[esp+8]`) | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ machine; decompiler this-loss corrected)

```
obj+8 = manager
if obj+0x40: attach(*(manager+0x2c)); ret
if manager+0x23c: new host; attach(host); push; ret
if count==0: new host; push
attach(list[0])
```

| Stage | Match | Conf |
|---|---|---|
| Stamp obj+8 | **Yes** | **High** |
| Early sticky path this=`*(mgr+0x2c)` | **Yes** (bytes) | **High** |
| Island alloc tag 0x2d / size 0xa8 | **Yes** | **High** |
| Fallthrough first-host attach | **Yes** (bytes) | **High** |
| thiscall + ret 4 | **Yes** | **High** |

### Decompiler residual (documented, not blocking)

Ghidra shows `FUN_006291e0(obj)` without host ECX. Bytes seal three distinct this sources. Clean + annotated carry machine CF.

---

## 5. Gaps / open

1. Product English for `manager+0x23c` and sticky `obj+0x40`.
2. Product type name for 0xa8 host (`FUN_006295f0`).
3. Nested duals of `006291e0` / `006295f0` / arena.
4. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/role sealed; decompiler this-loss corrected in clean.

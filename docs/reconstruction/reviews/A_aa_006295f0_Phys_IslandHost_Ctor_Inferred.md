# Review A (reconstruction fidelity): `aa_006295f0` Phys_IslandHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006295f0` |
| **VA** | `0x006295f0`–`0x006296a2` |
| **Body** | **178 bytes** (`0xB2`) |
| **Canonical name** | `Phys_IslandHost_Ctor_Inferred` |
| **Ghidra name** | `FUN_006295f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-J) |
| **Counterpart** | `reviews/B_aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` |
| **System** | phys / island host construct |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

**Thiscall constructor** for the **0xa8** island/host block:

1. Zero header fields; install primary vtbl `009e331c` and secondary `009e3310`.
2. Store **manager** at `host+0x20`.
3. Set flag bytes (`+0x29=1`, `+0x30=1`, others 0 as sealed).
4. Initialize empty growable list descriptors (capacity sentinels `0x80000000` / `0x80000001`).

Used by `WorldObj_AttachRegisterHost_Inferred` after arena alloc (`tag 0x2d`), and by island-split paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006295f0_FUN_006295f0.md` (+ W30-J append) |
| Annotated | `docs/reconstruction/raw/aa_006295f0_FUN_006295f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_IslandHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006295f0.cpp` |
| Function records | `functions/aa_006295f0_FUN_006295f0.md`, named twin |
| Live | decompile ≡ raw; body bytes through `ret 4`; vtbl rdata |
| Call sites | AttachRegisterHost: `PUSH mgr; MOV ECX,host; CALL` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of dtor `006296c0`.

---

## 3. Signature (sealed)

```c
// thiscall; ECX = host; stack manager; ret 4; void (EAX=this)
void Phys_IslandHost_Ctor_Inferred(uint32_t *host /*ECX*/, uint32_t manager);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`MOV EAX,ECX`) | **High** |
| manager | `[esp+4]` (`MOV EDX,[ESP+4]` → `host+0x20`) | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Zero +0x08..+0x18 | **Yes** | **High** |
| Vtbl primary/secondary | **Yes** (bytes + rdata) | **High** |
| manager @ +0x20 | **Yes** | **High** |
| Flag bytes | **Yes** | **High** |
| List descriptors / sentinels | **Yes** | **High** |
| No callees | **Yes** | **High** |
| thiscall + ret 4 | **Yes** | **High** |

### Decompiler residual (documented, not blocking)

Call sites assign `host = FUN_006295f0(manager)` — ctor-return-this; machine seals ECX=host before call.

---

## 5. Gaps / open

1. Product class English for 0xa8 host.
2. Element types of initialized list slots.
3. Nested dual of `FUN_006296c0` (dtor-like).
4. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/field map sealed; pure ctor with no callees.

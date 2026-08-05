# Review A (reconstruction fidelity): `aa_004bb950` Object_ResolveFromTFID

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb950` |
| **VA** | `0x004bb950`–`0x004bb966` (body; `ret 4`) |
| **Canonical name** | `Object_ResolveFromTFID` |
| **Review date** | `2026-07-29` (dual A/B seal; scaffold raw 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004bb950_Object_ResolveFromTFID.md` |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` body (2026-07-29); `analyze_function_complete`; `get_function_callers` / xrefs; call-site `get_assembly_context` (`004d0b94`, `00929f25`, `009198a5`, `00813fa3`); callee dual `aa_004bae70` |
| **Verdict** | **accept-with-gaps** (ABI + unpack **High**/sealed; ctx product type open) |

---

## 1. Purpose

Ubiquitous **TFID → live object\*** entry point:

1. Read packed `TFID_16*` from stack.
2. Unpack `dwCoidLo@+0`, `dwCoidHi@+4`, `bGlobal@+8`.
3. Invoke `CVOGReaction_ResolveObjectTarget(ctx, bGlobal, coidLo, coidHi)` with **ECX = resolve context** supplied by the caller (not loaded inside this body).
4. Return object* or NULL.

**No mutation.** No domain logic beyond field unpack; dual-table gates live in the callee.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bb950_FUN_004bb950.md` |
| Annotated | `docs/reconstruction/raw/aa_004bb950_FUN_004bb950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveFromTFID.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bb950_Object_ResolveFromTFID.md` |
| Counterpart B | `reviews/B_aa_004bb950_Object_ResolveFromTFID.md` |
| Callee | `CVOGReaction_ResolveObjectTarget` `0x004bae70` (dual A/B sealed) |
| TFID head layout | `TFID_EqualsObjectId` `0x00404aa0` (same +0/+4/+8) |

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = resolve context (reaction/world host tables)
// stack arg cleaned by ret 4  (1 dword)
void * __thiscall Object_ResolveFromTFID(
    void *ctx,        // this ECX — same ctx as ResolveObjectTarget
    TFID_16 *pTfid);  // stack [esp+4] after entry
// returns object* or NULL (from callee hash lookup)
```

| Item | Evidence |
|---|---|
| Stack arity 1 | `RET 4` @ `0x004bb964` |
| ECX this | Body never writes ECX; call sites `MOV ECX,[…+0xe4e8]` / `[…+0xd34]` immediately before `CALL 0x004bb950` |
| Sole callee | `CALL rel32` → `0x004bae70` only |
| Classification | Ghidra `wrapper` |

**Decompiler trap:** Ghidra signature `void * __stdcall Object_ResolveFromTFID(TFID_16*)` and decompile without `this` are **wrong on ABI** — bytes + callers seal thiscall passthrough.

---

## 4. Control flow (assembly-sealed)

```
// 0x004bb950 (read_memory 2026-07-29)
eax = pTfid;                         // [esp+4]
push *(u32*)(pTfid + 4);             // coidHi
edx = *(u32*)(pTfid + 0);            // coidLo
al  = *(u8*)(pTfid + 8);             // bGlobal (AL only)
push edx;                            // coidLo
push eax;                            // bGlobal in low byte (upper bits residual)
eax = CVOGReaction_ResolveObjectTarget(ctx /*ECX*/, bGlobal, coidLo, coidHi);
ret 4;
```

| Stage | Match clean≡image | Confidence |
|---|---|---|
| Load pTfid from stack+4 | **Yes** | **High** |
| Unpack +0 / +4 / +8 only | **Yes** | **High** |
| Push order hi, lo, bGlobal → callee stack bGlobal, lo, hi | **Yes** | **High** |
| ECX preserved into Resolve | **Yes** (no `mov ecx` in body; callers set) | **High** |
| `CALL 0x004bae70` | **Yes** (rel32) | **Confirmed** |
| `RET 4` | **Yes** | **Confirmed** |
| No branches / no stores | **Yes** | **High** |
| Null-safe pTfid | **No** — null faults | **High** |

### bGlobal push quirk

`MOV AL,[tfid+8]` leaves upper 24 bits of EAX as residual pointer bits; full EAX is pushed. Callee `cmp byte ptr [esp+4],0` only — **behavior-safe**. Clean may zero-extend; ports must not require upper bits clean if matching residual, but only the low byte is semantic.

---

## 5. Machine bytes (`read_memory` @ `0x004bb950`)

```
8B 44 24 04    MOV  EAX, [ESP+4]
8B 50 04       MOV  EDX, [EAX+4]
52             PUSH EDX
8B 10          MOV  EDX, [EAX]
8A 40 08       MOV  AL,  [EAX+8]
52             PUSH EDX
50             PUSH EAX
E8 0C F5 FF FF CALL 0x004bae70
C2 04 00       RET  4
```

Hex: `8b4424048b5004528b108a40085250e80cf5ffffc20400`

---

## 6. Callee contract (boundary; owned residual stops at call)

| Addr | Role | Sealed bits (from `aa_004bae70` dual) |
|---|---|---|
| `CVOGReaction_ResolveObjectTarget` `0x004bae70` | Dual-table resolve | Invalid `(lo&hi)==-1` → 0; `bGlobal==0` → flag `ctx+0xd` / table `ctx+0x8`; else flag `ctx+0xc` / table `ctx+0x4`; `FUN_004e3260` → object* @ node `+0xc` |

This unit **does not** re-own hash walk math.

---

## 7. Representative callers (mode evidence)

| Caller | ECX source (call-site) | Notes |
|---|---|---|
| `CVOGReaction_CastSkillOnTarget` `0x004d0b94` | `[EAX+0xe4e8]` | skill target TFID walk |
| `Client_FindFirstObjectInRadius` `0x009198a5` | `[[DAT_00d1b644]+0xe4e8]` | world scan / auto-patrol path |
| `Client_EvalAutoPatrolWaypoint` `0x00929f25` | `[ECX+0xd34]` | waypoint TFID resolve |
| `Client_RecvInventoryEquip` `0x00813fa3` | `[EAX+0xe4e8]` | item TFID on equip |
| Many Recv* / interact / drive / combat | same family | ≥100 xrefs |

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x004bb950` | **Confirmed** | Ghidra + bytes |
| Thin unwrap only | **High** | straight-line body |
| TFID fields +0/+4/+8 | **High** | matches EqualsObjectId head |
| `__thiscall` + 1 stack ptr (`RET 4`) | **High** | image + call sites |
| Sole callee ResolveObjectTarget | **Confirmed** | rel32 |
| Return = object* or NULL | **High** | callee dual |
| No mutation here | **High** | no stores |
| ctx C++ type / +0xe4e8 field English | **Tentative** | caller layout |
| Product name of dual tables | **Open** | callee residual |

---

## 9. Gaps

1. Product / PDB name confirmation (plate already `Object_ResolveFromTFID`).
2. Exact C++ type of resolve `ctx` and host offsets `+0xe4e8` / `+0xd34`.
3. Runtime / differential / bit-exact vs retail image.
4. Whether any call site intentionally uses a non-standard ctx with different table layout (would break Resolve, not this unpack).

**Verdict:** **accept-with-gaps**.

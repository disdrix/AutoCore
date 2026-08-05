# Review A (reconstruction fidelity): `aa_0059e1c0` RPC_rpcMsgGuaranteedOrdered_Method1

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059e1c0` |
| **VA** | `0x0059e1c0` |
| **Canonical name** | `RPC_rpcMsgGuaranteedOrdered_Method1` (Ghidra) |
| **Proposed semantic name** | `RPC_TNLConnection_rpcMsgGuaranteedOrdered_getClassRep` |
| **Review date** | `2026-07-29` (dual A/B seal) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw / dual residual) |
| **Counterpart** | `reviews/B_aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |
| **System** | `networking` / TNL RPC event class-rep |
| **Verdict** | **accept** (runtime/diff open; body + return target + ClassRep identity sealed) |

---

## 1. Purpose

Trivial **virtual ClassRep accessor** for the TNL RPC event class
`RPC_TNLConnection_rpcMsgGuaranteedOrdered`:

* Body loads immediate address `0x00b04f40` into **EAX** and returns.
* `DAT_00b04f40` is the static `TNL::NetClassRepInstance<RPC_TNLConnection_rpcMsgGuaranteedOrdered>`
  (RTTI + CRT init + ClassRep ctor sealed below).
* Vtable slot 0 of `PTR_RPC_rpcMsgGuaranteedOrdered_Method1_009d7c8c` — installed on
  heap RPC event objects by factories `FUN_0059ea60` / `FUN_0059eb40` / `FUN_0059ec00` /
  `FUN_005a2b10`.

No pack/unpack/dispatch logic lives here. Those are sibling vtable slots
(`FUN_00780810` / `FUN_00780800` / `FUN_007807e0` / `RPC_rpcMsgGuaranteedOrdered_Execute`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |
| Annotated | `docs/reconstruction/raw/aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RPC_rpcMsgGuaranteedOrdered_Method1.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1.md` |
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x0059e1c0` (2026-07-29) |
| Live memory (body) | Ghidra `read_memory` `0x0059e1c0` (16 B) |
| Live memory (ClassRep BSS) | Ghidra `read_memory` + `analyze_data_region` `0x00b04f40` (span **0x38**) |
| Live memory (vtbl) | Ghidra `read_memory` `0x009d7c8c` |
| Live memory (class name) | Ghidra `read_memory` `0x009d80cc` |
| CRT static init | bytes @ `0x009c0eb0` + ClassRep ctor `FUN_005a2410` @ `0x005a2410` |
| Atexit dtor wrapper | `FUN_009c3de0` → `FUN_005a2470` |
| Event factories (vtbl install) | `FUN_0059ea60`, `FUN_0059eb40`, `FUN_0059ec00`, `FUN_005a2b10` |
| Execute sibling | `RPC_rpcMsgGuaranteedOrdered_Execute` @ `0x005a2a50` |
| RTTI / strings | Ghidra `search_strings` `rpcMsgGuaranteed` |

---

## 3. Body (authoritative asm / memory)

```text
0059e1c0  MOV  EAX, 0x00b04f40
0059e1c5  RET
```

Body hex (live `read_memory` 2026-07-29):

```text
b8 40 4f b0 00 c3 cc cc cc cc cc cc cc cc cc cc
```

| Bytes | Decode |
|---|---|
| `b8 40 4f b0 00` | `mov eax, 0x00b04f40` |
| `c3` | `ret` |
| `cc…` | int3 pad after function end |

Ghidra function span: **`0059e1c0`–`0059e1c5`**. Classification: **stub**.

Decompile (CF-identical to raw scaffold):

```c
undefined * RPC_rpcMsgGuaranteedOrdered_Method1(void)
{
  return &DAT_00b04f40;
}
```

No callees. No stack formals. No branches. **ECX unused** (vtable `this` ignored).

---

## 4. ABI seal (High)

| Claim | Evidence | Conf |
|---|---|---|
| Return in **EAX** | `MOV EAX, imm32` | **High** |
| Return value = **pointer** to `DAT_00b04f40` | Immediate `40 4f b0 00` LE | **High** |
| No stack args | Bare `RET` (`c3`); no `RET n` | **High** |
| Virtual dispatch | Sole code xref is **DATA** at vtbl `0x009d7c8c` slot 0 | **High** |
| `this` unused | No `[ECX+…]` / no ECX write | **High** |
| Convention at call sites | Vtable call → **`__thiscall`** (ECX = event instance) even though body ignores it | **High** |

Canonical signature:

```c
// Ghidra name retained; semantic alias:
TNL::NetClassRep* /*EAX*/
  __thiscall RPC_TNLConnection_rpcMsgGuaranteedOrdered_getClassRep(
      RPC_TNLConnection_rpcMsgGuaranteedOrdered* /*ECX this, unused*/);
// Body: return &g_rpcMsgGuaranteedOrdered_ClassRep; // DAT_00b04f40
```

---

## 5. Return target identity — NetClassRepInstance (High)

### 5.1 Size / region

| Claim | Evidence | Conf |
|---|---|---|
| Object span **0x38** (56 B) | `analyze_data_region`: `00b04f40`–`00b04f77` | **High** |
| Next sibling ClassRep @ `0x00b04f78` | Adjacent Method stub `MOV EAX, 0x00b04f78` @ `0x0059e1d0` pattern | **High** (layout) |
| Linked ClassRep list head `DAT_00d179a4` | Ctor `FUN_005a2410` writes `param_1[0xd] = DAT_00d179a4; DAT_00d179a4 = param_1` | **High** |

### 5.2 CRT static construction @ `0x009c0eb0`

Live bytes:

```text
6a 00 6a 02 6a 01 68 cc 80 9d 00 b9 40 4f b0 00 e8 …  ; call FUN_005a2410
68 e0 3d 9c 00 e8 … 59 c3                              ; atexit(FUN_009c3de0)
```

| Stack / reg | Value | Role |
|---|---|---|
| ECX | `0x00b04f40` | `this` = ClassRep storage |
| pushed name | `0x009d80cc` | ASCII `RPC_TNLConnection_rpcMsgGuaranteedOrdered` |
| pushed | `1` | class group mask (bit 0) |
| pushed | `2` | **NetClassTypeEvent** (TNL class type enum) |
| pushed | `0` | class version |
| atexit | `FUN_009c3de0` → `FUN_005a2470` | ClassRep dtor (free name, restore base vtbl) |

`FUN_005a2410` (`__thiscall`):

* Base init `FUN_0042aea0`
* `*this = &PTR_FUN_009d7bf4` (NetClassRepInstance vtbl)
* `this[8] = strdup(name)`
* `this[1] = group (1)`, `this[3] = type (2)`, `this[2] = version (0)`
* zeros counters / ids at `[4..7]`
* splices into global ClassRep list via `DAT_00d179a4`

### 5.3 RTTI / product strings (High)

| Address | String |
|---|---|
| `0x009d80cc` | `RPC_TNLConnection_rpcMsgGuaranteedOrdered` |
| `0x00af37f8` | `.?AV?$NetClassRepInstance@VRPC_TNLConnection_rpcMsgGuaranteedOrdered@@@TNL@@` |
| `0x00af3a6c` | `.?AVRPC_TNLConnection_rpcMsgGuaranteedOrdered@@` |

**Conclusion:** `DAT_00b04f40` **is** the static ClassRep for the GuaranteedOrdered game-message RPC event class. Method1 **returns that ClassRep\***.

---

## 6. Vtable context (ownership note — slot 0 only)

`PTR_RPC_rpcMsgGuaranteedOrdered_Method1_009d7c8c` @ `0x009d7c8c` (first dword = this unit):

| Slot | VA | Role (sealed / adjacent) |
|---|---|---|
| +0x00 | `0x0059e1c0` | **This unit** — getClassRep |
| +0x04 | `0x005a2970` | Scalar deleting dtor (`FUN_005a2990` + optional `operator_delete`) |
| +0x08 | `0x00424c80` | Delete helper → vtbl+4 |
| +0x0C | `0x00780810` | Pack path via functor at `this+0x14` |
| +0x10 | `0x00780800` | Unpack path via functor |
| +0x14 | `0x007807e0` | Process / dispatch path |
| +0x18 / +0x1C | `0x005ffc80` | Empty stubs |
| +0x20 | `0x004648a0` | Empty stub |
| +0x28 | `0x005a2a50` | `RPC_rpcMsgGuaranteedOrdered_Execute` — `dynamic_cast` to `TNLConnection` |
| +0x2C | `0x00aaf95c` | Static data / type cookie (not owned here) |

Event object size **0x28** from factories (`operator_new(0x28)`); NetEvent base ctor
`FUN_00780820(guarantee=0, direction=1)` → **RPCGuaranteedOrdered** + **DirAny** (enum
aligned with in-repo `TNL.NET` `RPCGuaranteeType.RPCGuaranteedOrdered = 0`).

Xrefs **to** this function: **1** — DATA at `0x009d7c8c` only (no direct CALL sites).

Xrefs **to** ClassRep storage `0x00b04f40`: Method1, CRT init `0x009c0ebb`, atexit path
registration region / `FUN_009c3de0` family.

---

## 7. Confidence

| Claim | Level |
|---|---|
| Control flow: mov imm / ret only | **High** |
| Immediate = `0x00b04f40` | **High** |
| Return = ClassRep* for GuaranteedOrdered RPC | **High** |
| Product class name `RPC_TNLConnection_rpcMsgGuaranteedOrdered` | **High** |
| Type = NetClassTypeEvent (2), group=1, version=0 | **High** |
| Semantic C++ name `getClassRep` | **High** (vtbl slot 0 + TNL Object pattern + ClassRep return) |
| Ghidra `Method1` label | **High** as stable symbol; not product English |
| Runtime / bit-for-bit image | **Open** |
| Full ClassRep field layout beyond ctor writes | **Probable** (ctor stores sealed; live BSS often zero pre-run) |
| Sibling RPC Method stubs (Guaranteed / Fragmented) | **Out of unit** — same pattern, not owned |

---

## 8. Port contract (AutoCore)

```
// No gameplay logic. Class registration / NetEvent polymorphism only.
NetClassRep* GetClassRep_rpcMsgGuaranteedOrdered() {
  return &g_RPC_TNLConnection_rpcMsgGuaranteedOrdered_ClassRep; // VA 0x00b04f40
}

// Port rules:
//  - Do NOT invent pack/unpack here — those are other vtbl slots + Functor.
//  - Guarantee type for this event class is GuaranteedOrdered (0) at factory ctor.
//  - Execute gate is aa_005a2a50 (TNLConnection dynamic_cast) — separate unit.
//  - AutoCore SendGamePacket default RPCGuaranteedOrdered matches this event family.
```

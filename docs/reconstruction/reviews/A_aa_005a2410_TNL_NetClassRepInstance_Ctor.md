# Review A (reconstruction fidelity): `aa_005a2410` TNL_NetClassRepInstance_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2410` |
| **VA** | `0x005a2410` |
| **Body span** | `005a2410`–`005a2466` (87 B through `ret 0x10`) |
| **Canonical name** | `TNL_NetClassRepInstance_Ctor` |
| **Ghidra name** | `FUN_005a2410` |
| **Review date** | `2026-07-29` (W21-K dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005a2410_TNL_NetClassRepInstance_Ctor.md` |
| **System** | `tnl` / NetClassRep |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

In-place **TNL NetClassRepInstance ClassRep constructor**: base ClassRep init, install NetClassRepInstance vtbl, strdup class name, store group/type/version, zero classId bank, prepend to global ClassList (`DAT_00d179a4`).

Matches product shape of `TNL.NET` `NetClassRepInstance(className, groupMask, classType, classVersion)` + `ClassList.Add(this)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a2410_FUN_005a2410.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_005a2410_FUN_005a2410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TNL_NetClassRepInstance_Ctor.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_005a2410.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a2410_TNL_NetClassRepInstance_Ctor.md` |
| Live decompile | Ghidra @ `0x005a2410` — **≡ raw** |
| Bytes | `read_memory` 128 B @ `0x005a2410` |
| CRT caller | `read_memory` @ `0x009c0eb0` |
| Name string | `read_memory` @ `0x009d80cc` → `RPC_TNLConnection_rpcMsgGuaranteedOrdered` |
| Sibling dual | `A_aa_0059e1c0_RPC_rpcMsgGuaranteedOrdered_Method1` (ClassRep identity) |
| TNL.NET | `lib/TNL.NET/.../NetClassRepInstance.cs` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x005a2410`)

Hex (87 B through `ret 0x10`):

```
568bf1e8888ae8ff8b44240850c706f47b9d00ff1574649c008b4c24148b5424108946208b442418894608894e0c89560433c089461089461489461889461c8b0da479d100894e3483c4048935a479d1008bc65ec21000
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **87 bytes** through `C2 10 00` | hex + `CC` pad; next fn @ `005a2470` | **Confirmed** |
| `__thiscall` ECX=this, 4 stack dwords | `mov esi,ecx` + `ret 0x10` | **Confirmed** |
| Base init `FUN_0042aea0` | `E8` rel → `0042aea0` | **Confirmed** |
| Vtbl write `009d7bf4` | `C7 06 F4 7B 9D 00` | **Confirmed** |
| `_strdup` IAT | `FF 15 74 64 9C 00` + `add esp,4` | **Confirmed** |
| Stores: name@+0x20, ver@+8, type@+0xC, group@+4 | `89 46 20` / `08` / `0C` / `04` | **Confirmed** |
| Zero +0x10..+0x1C | four `89 46 1x` after `xor eax,eax` | **Confirmed** |
| List splice via `DAT_00d179a4` | read/write `A4 79 D1 00`, link @ `+0x34` | **Confirmed** |
| Return this | `mov eax,esi` | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Base init then vtbl | **Yes** |
| strdup → +0x20 | **Yes** |
| Field store order (ver, type, group) | **Yes** (matches decompile param_5/4/3) |
| Zero classId[4] | **Yes** |
| Prepend ClassList | **Yes** |
| `ret 0x10` | **Yes** |

---

## 5. CRT / product identity (High)

Caller @ `0x009c0eb0`:

```text
push 0; push 2; push 1; push 0x009d80cc; mov ecx, 0x00b04f40; call 0x005a2410
```

| Arg | Value | Role |
|---|---|---|
| this | `DAT_00b04f40` | ClassRep storage (span 0x38) |
| name | `RPC_TNLConnection_rpcMsgGuaranteedOrdered` | product string |
| groupMask | `1` | game group bit |
| type | `2` | `NetClassTypeEvent` |
| version | `0` | class version |

RTTI (sibling dual): `.?AV?$NetClassRepInstance@VRPC_TNLConnection_rpcMsgGuaranteedOrdered@@@TNL@@`.

---

## 6. Gaps

1. Other ClassRep ctor entry points sharing `DAT_00d179a4` (not this VA).
2. Base ClassRep field product names for slots only touched by `FUN_0042aea0`.
3. Runtime ClassList walk / Initialize bit sizes — open.
4. Exhaustive CRT call-site catalog for this exact entry — Ghidra shows one xref; other templates may use sibling ctors.

**Verdict:** **accept**

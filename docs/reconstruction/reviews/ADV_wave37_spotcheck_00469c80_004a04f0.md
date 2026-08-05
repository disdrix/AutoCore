# Independent adversarial spot-check — W37-C duals `0x00469c80` + `0x004a04f0`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** W37-C dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | W37-C (high value: POD vector push + mission media preload walk) |
| **Tools** | Ghidra MCP `decompile_function`, `read_memory`, `get_xrefs_to`, `get_function_callers`; artifact read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00469c80-004a04f0-w37c-report.md` |
| `docs/reconstruction/reviews/A_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |

### Artifacts

| Kind | `aa_00469c80` | `aa_004a04f0` |
|---|---|---|
| Raw (+ W37-C append) | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.md` | `…/aa_004a04f0_FUN_004a04f0.md` |
| Annotated | `…/aa_00469c80_FUN_00469c80.annotated.md` | `…/aa_004a04f0_FUN_004a04f0.annotated.md` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469c80.cpp` | `…/FUN_004a04f0.cpp` |
| Clean named | `…/StdVector_PushBack_Elem28_ValueEax_Inferred.cpp` | `…/MissionTree_InorderCollectMediaPreloads_Inferred.cpp` |
| Function named | `docs/reconstruction/functions/aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` | `…/aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `decompile_function(0x00469c80)` | Live ≡ raw scaffold CF: size/cap via `/0x1c`, spare → `FUN_0046a260` + `end+=0x1c`, full → `FUN_00469e20(&local, end, in_EAX)` |
| `decompile_function(0x004a04f0)` | Live ≡ raw scaffold CF: head/`begin` empty gate, loop, successor left/parent/right + nil `@+0x15`, sole callee `FUN_004b88e0` |
| `decompile_function(0x004ebf50)` | Plate `CollectAllSoundPreloads`; gate `this+0x88`; `FUN_004a04f0(param_2,0,1,0)` |
| `decompile_function(0x004ec7b0)` | Plate `CollectAllPhysicsPreloads`; gate `this+0x88`; `FUN_004a04f0(param_2,0,0,1)` |
| `get_xrefs_to(0x00469c80)` | 3 sites: `0071a8ec`, `009833e6`, `0098485e` |
| `get_xrefs_to(0x004a04f0)` | 5 sites: `004ebfa4`, `004ec871`, `004f2500`, `005429cc`, `00542f5b` |
| `read_memory` full bodies | See hex/CF tables below |
| Pad after bodies | `0x00469d04` = `CC×4`; `0x004a057a` = `CC×4` |

---

## Live bytes vs dual claims

### `0x00469c80` body (132 B / `0x84`)

Live `read_memory` hex (body only; pad excluded):

```
51535556578bf98b6f0485ed8bd8750433f6eb188b4f082bcdb893244992f7e903d1c1fa048bf2c1ee1f03f285ed743f8b4f0c2bcdb893244992f7e903d1c1fa048bc2c1e81f03c23bf073238b4424108b770850b9010000008bc6e88005000083c40483c61c8977085f5e5d5b59c38b470853508d4c241851e8220100005f5e5d5b59c3
```

| Claim | Live evidence | Verdict |
|---|---|---|
| Exclusive range `00469c80`–`00469d04` (132 B) | len=132; `C3` @ `00469cee` and `00469d03`; pad `CC` @ `00469d04` | **Confirmed** |
| Entry ABI: `mov edi,ecx` / `mov ebx,eax` | `8B F9` then later `8B D8` after `mov ebp,[edi+4]` | **Confirmed** |
| Magic `/0x1c` via `0x92492493` | `B8 93 24 49 92` ×2 (size + cap) | **Confirmed** |
| Fast path `ECX=1`, call `0046a260` | `B9 01 00 00 00 8B C6 E8…` @ `00469cdb` → **tgt `0046a260`** | **Confirmed** |
| `end += 0x1c` | `83 C6 1C` / `89 77 08` | **Confirmed** |
| Slow path call `00469e20` | `E8 22 01 00 00` @ `00469cf9` → **tgt `00469e20`** | **Confirmed** |
| Bare `RET` (`C3`) both paths | epilogues `5F 5E 5D 5B 59 C3` | **Confirmed** |
| Distinct from RC push `00460f90` (EAX=vec / ECX=value) | W36-O record seals opposite register map; this body never loads value from stack | **Confirmed** |

**Decompiler caveat (correctly handled by dual):** live decompile shows `FUN_0046a260(param_1)` and phantom `in_EAX`. Bytes win: fill-n is register ABI (`ECX=count`, `EAX=dest`, `EBX=tmpl`); value-in-EAX is real (`mov ebx,eax` + push EBX on slow path). A/B/raw append privilege bytes — **correct**.

### `0x004a04f0` body (138 B / `0x8A`)

Live `read_memory` hex (body only):

```
518b018b4004568b303bf0894c24047474538b5c2414558b6c241c578b7c24188b4c2424518b4e10555357e8c0830100807e150075418b460880781500751d8bf08b0680781500752e8da424000000008bf08b068078150074f6eb1b8b46048078150075103b7008750b8bf08b40048078150074f08bf08b5424108b023b7004759e5f5d5b5e59c21000
```

| Claim | Live evidence | Verdict |
|---|---|---|
| Exclusive range `004a04f0`–`004a057a` (138 B) | len=138; pad `CC` @ `004a057a` | **Confirmed** |
| `RET 0x10` (`C2 10 00`) | @ `004a0577` | **Confirmed** |
| thiscall holder: `*ecx` then `+4` head | `8B 01 8B 40 04` | **Confirmed** |
| begin = `*head`; empty `begin==head` | `8B 30 3B F0` + early exit | **Confirmed** |
| Payload → callee ECX: `[node+0x10]` | `8B 4E 10` before call | **Confirmed** (decompiler **omits** this — bytes win) |
| Sole callee `004b88e0` | `E8 C0 83 01 00` @ `004a051b` → **tgt `004b88e0`** | **Confirmed** |
| Nil-gate `@+0x15` | `80 7E 15 00` and sibling `80 78 15 00` | **Confirmed** |
| Inorder successor (+0 left / +4 parent / +8 right) | decompile ≡ bytes (right-min then parent climb) | **Confirmed** |

### Parent flag triples (`0x004a04f0` callers)

Push order last→first; signature `(unused, f_media, f_audio, f_paths)`.

| Parent | Site | Live stack pattern | Flags | Call tgt |
|---|---|---|---|---|
| `004ebf50` Sound | `004ebfa4` | `6A 00 6A 01 6A 00 50` + `E8` | `(ctx,0,1,0)` | **`004a04f0`** |
| `004ec7b0` Physics | `004ec871` | `8B 8E 88 00 00 00` … `6A 01 6A 00 6A 00 53` + `E8` | `(ctx,0,0,1)`; ECX=`[esi+0x88]` | **`004a04f0`** |
| `004f1ff0` Graphics | `004f2500` | `6A 00 6A 00 6A 01 52` + `E8` | `(ctx,1,0,0)` | **`004a04f0`** |
| `00542790` | `005429cc` | three `6A 01` + push lea + `E8` | `(…,1,1,1)` | **`004a04f0`** |
| `00542e20` | `00542f5b` | three `6A 01` earlier; `LEA ECX,[ebp+4]` + `E8` | `(…,1,1,1)` embed holder | **`004a04f0`** |

Sound/physics decompiles also seal plate strings and flag triples independently of call-site hex.

---

## Confirmed claims

### `0x00469c80` — `StdVector_PushBack_Elem28_ValueEax_Inferred`

| Claim | Verdict |
|---|---|
| Worker thin push_back router for POD stride **0x1c** | **Confirmed** |
| Layout `+0x04 begin / +0x08 end / +0x0c cap_end` | **Confirmed** |
| Spare → W36-M fill-n count 1 + end advance; full → W36-Q insert-one-at-end | **Confirmed** (call targets live) |
| ABI **ECX=vec / EAX=value / bare RET** | **Confirmed** |
| Not unify with RC twin `00460f90` | **Confirmed** (ABI inverted) |
| Callers (3) match dual list | **Confirmed** via `get_xrefs_to` |
| Name `_Inferred` structural; reject scaffold `Named_CalleeOf_*assPackManag*` | **Appropriate** |
| Clean twin + named clean match sealed CF | **Confirmed** |
| Dual A/B both `accept-with-gaps` | **Appropriate** |

### `0x004a04f0` — `MissionTree_InorderCollectMediaPreloads_Inferred`

| Claim | Verdict |
|---|---|
| Worker walk-only bridge (no path/string logic in-body) | **Confirmed** |
| thiscall + 4 stack dwords + **RET 0x10** | **Confirmed** |
| Inorder walk → `MissionHost_CollectMediaPreloads` (`004b88e0`) | **Confirmed** |
| ECX at call = payload `[node+0x10]`, **not** tree holder | **Confirmed** (bytes; decompile incomplete) |
| Five callers / independent flag triples | **Confirmed** |
| CollectAll* gate often `obj+0x88`; mission residual may embed | **Confirmed** (bytes + dual residual wording) |
| Name `_Inferred` structural; reject `Named_CalleeOf_*VOG_DEBUG*` | **Appropriate** |
| Clean models inorder successor + flag forward | **Confirmed** (semantic; not bit-exact) |
| Dual A/B both `accept-with-gaps` | **Appropriate** |

---

## Adversarial attacks (this pass)

| Attack | Result |
|---|---|
| Same register ABI as RC push `00460f90`? | **No** — opposite vec/value registers |
| `in_EAX` phantom / value on stack? | **No** — `mov ebx,eax`; value never stack-loaded in body |
| Fill-n takes stack vec formal (decompiler)? | **No** — `ECX=1/EAX=end/EBX=value`; dead push cleaned |
| Body owns media string collect? | **No** — sole callee `004b88e0` |
| Tree holder ECX is mission host? | **No** — host from `node+0x10` |
| Preorder/postorder not inorder? | **No** — textbook right-min / parent-climb successor |
| RET 0x10 wrong width (3 vs 4 stack args)? | **No** — four pushes at all CollectAll* sites; `C2 10 00` |
| Hex in raw W37-C append ≠ live image? | **No** — byte-identical for both bodies |
| Caller counts inflated? | **No** — xrefs match dual exactly |
| Clean invents product plates? | **No** — structural `_Inferred` only |

---

## Residual gaps (honest; duals already flag most)

1. **Product/PDB English** for POD `Elem28` T and tree/holder/node types.  
2. **Caller container product names** for `00469c80` parents (`0071a4a0` / `00983350` / `009847c0`) — not OWN.  
3. **Holder first-indirection field map** (`*ecx` then `+4` head) beyond structural walk.  
4. **+0x15 vs stock MSVC `_Isnil` naming** — behavior sealed; English residual.  
5. **Clean `TreeNode` layout** incomplete around payload/`+0x15` (pad comment acknowledges); CF uses byte offsets correctly.  
6. **Runtime / bit-exact / differential** open; terminal coverage claimed false; no Launcher.  
7. **Decompiler thiscall/register formals incomplete** on both units — duals correctly privilege `read_memory` (not a dual failure).

No sealed numeric/flag/ABI claim was falsified.

---

## Pass / fail

### `aa_00469c80` — **PASS**

- Dual quality: solid.  
- Verdict retention: keep **`accept-with-gaps`**.  
- Action: none required.

### `aa_004a04f0` — **PASS**

- Dual quality: solid (high-value walk bridge sealed).  
- Verdict retention: keep **`accept-with-gaps`**.  
- Action: none required.

### Pair summary

| VA | Dual quality | Verdict retention | Action |
|---|---|---|---|
| `0x00469c80` | **PASS** | keep **accept-with-gaps** | none |
| `0x004a04f0` | **PASS** | keep **accept-with-gaps** | none |

**Overall W37-C pair: PASS.** High-value seals stand: POD ValueEax push_back parent of W36-M/W36-Q, and mission-tree inorder forwarder into W32-H `004b88e0` with parent flag triples.

---

## Process notes

- Independent of dual author; no parent ledger / WORK_QUEUE / COVERAGE_LEDGER edits.  
- Seal tools only: `decompile_function` + `read_memory` + xrefs/callers. **No** `disassemble_bytes`.  
- Call targets recomputed from live relative `E8` immediates (not trusted prose alone).  
- Output: this file only.

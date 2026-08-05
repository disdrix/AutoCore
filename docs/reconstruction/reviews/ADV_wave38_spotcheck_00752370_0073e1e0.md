# Independent adversarial spot-check — W38-Q duals `0x00752370` + `0x0073e1e0`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** W38-Q dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | W38-Q OWN pair — effect param find + effect create/load |
| **Tools** | Ghidra MCP `batch_decompile` / `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`; artifact read-through (report + A/B + raw + clean) |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00752370-0073e1e0-w38q-report.md` |
| `docs/reconstruction/reviews/A_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` |

### Artifacts

| Kind | `aa_00752370` | `aa_0073e1e0` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00752370_FUN_00752370.md` | `docs/reconstruction/raw/aa_0073e1e0_FUN_0073e1e0.md` |
| Annotated | `…/aa_00752370_FUN_00752370.annotated.md` | `…/aa_0073e1e0_FUN_0073e1e0.annotated.md` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00752370.cpp` | `…/FUN_0073e1e0.cpp` |
| Clean named | `…/EffEffect_FindParamIndexByName_Inferred.cpp` | `…/EffEffect_CreateAndLoad_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00752370_FUN_00752370.md` | `…/aa_0073e1e0_FUN_0073e1e0.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `batch_decompile(0x00752370, 0x0073e1e0)` | Live CF ≡ raw scaffold for both units |
| `get_function_by_address(0x00752370)` | Body `00752370`–`007523ca` → exclusive end `007523cb` (**91 B / 0x5b**) |
| `get_function_by_address(0x0073e1e0)` | Body `0073e1e0`–`0073e256` → exclusive end `0073e257` (**119 B / 0x77**) |
| `read_memory 0x00752370` len 100 | Full body hex ≡ raw W38-Q append; dual `ret 8` (`c2 08 00`) both paths; pad `CC` |
| `read_memory 0x0073e1e0` len 128 | Full body hex ≡ raw W38-Q append; dual `ret 0xc` (`c2 0c 00`) both paths; pad `CC` |
| `get_function_callers(0x00752370)` | **35** caller functions (matches dual) |
| `get_function_xrefs(0x00752370)` | **86** UNCONDITIONAL_CALL sites (matches dual) |
| `get_function_callers` / xrefs `0x0073e1e0` | **2** callers: `FUN_009701d0` @ `009701e7`, `FUN_0072a660` @ `0072a92a` |
| `decompile FUN_00457040` | Freelist pop; chain step `+0xc` dwords = **0x30** block; uses `unaff_EDI` pool head |
| `decompile FUN_007533e0` | thiscall path/ECX + effect + flag; status `<0` fail; writes `effect+8` inner |
| `decompile FUN_0073d830` + `read_memory` | See **soft overclaim** below (not a simple always-insert register) |
| `read_memory 0x00a9f9c4` | Vtbl dword0 = `0x00445020` (scalar deleting dtor) |
| `read_memory 0x00a9ede4` | `"DiffuseTexture"` C-string (caller evidence for finder) |
| `decompile FUN_009701d0` | Primary loader consumer: `FUN_0073e1e0(DAT_00d1f61c, path, &status)` then AddRef / slot swap |

---

## Byte-level ABI re-verify

### `0x00752370` (finder)

Decoded from live `read_memory` (no disassembly tool):

| Fact | Byte evidence | Dual claim |
|---|---|---|
| thiscall | `56 8b f1` → `push esi; mov esi, ecx` | **OK** |
| default index −1 | `83 cf ff` → `or edi, -1` | **OK** |
| `effect+8` inner | `8b 46 08` | **OK** |
| iface at `inner+0xc` | `83 78 0c 00` / `8b 40 0c` | **OK** |
| `vtbl+0x24(iface, 0, name)` | `push name; push 0; push iface; call [ecx+0x24]` with `ecx=vtbl` | **OK** (stack-this method; dual does not claim MSVC thiscall on iface) |
| table `+0x10`, count `+0x18`, stride 8 | `8b 71 10` / `8b 51 18` / `39 04 ce` (`cmp [esi+ecx*8], eax`) | **OK** |
| always write `*outIndex` | both paths `mov [eax], edi` via `[esp+0xc]` | **OK** |
| epilogue | `c2 08 00` ×2 | **OK** — `ret 8` |

### `0x0073e1e0` (create/load)

| Fact | Byte evidence | Dual claim |
|---|---|---|
| freelist pool | `bf 70 19 d2 00` → `mov edi, 0x00d21970`; `call FUN_00457040` | **OK** |
| vtbl install | `c7 00 c4 f9 a9 00` → `*[obj]=0x00a9f9c4` | **OK** |
| zero `+4..+0x18`, `+0x20` | `mov [eax+off], edi` with edi=0 | **OK** |
| `+0x1c/+0x1e = 0xFFFF` | `or ecx,-1; mov [eax+0x1c],cx; mov [eax+0x1e],cx` | **OK** |
| path → ECX into load | `mov ecx, [esp+0x10]` then `push 0; push obj; call FUN_007533e0` | **OK** (bytes win over decompiler’s incomplete arity) |
| `*outStatus = status` | `mov ecx, [esp+0x14]; mov [ecx], eax` | **OK** |
| fail → `vtbl[0](1)` + null | `push 1; mov ecx,esi; call [edx]; xor eax,eax` | **OK** |
| success → manager ECX + return obj | `mov ecx, [esp+0xc]; push esi; call FUN_0073d830; mov eax,esi` | **OK** (call site sealed) |
| epilogue | `c2 0c 00` ×2 | **OK** — stdcall 3 stack args |
| freelist block 0x30 | `FUN_00457040` freelist link step `piVar2 + 0xc` dwords | **OK** |

---

## Confirmed claims

### `0x00752370` (`aa_00752370` / `EffEffect_FindParamIndexByName_Inferred`)

| Claim | Verdict |
|---|---|
| Body `00752370`–`007523cb` exclusive, 91 B | **Confirmed** |
| Live decompile ≡ raw CF | **Confirmed** |
| `__thiscall` ECX=effect; stack `(int* outIndex, nameOrToken)`; **`ret 8`** | **Confirmed** |
| Default / miss → `*outIndex = -1`; always write | **Confirmed** |
| Handle resolve via iface `vtbl+0x24(iface, 0, name)`; zero handle → −1 | **Confirmed** |
| Linear scan table base `inner+0x10`, count `inner+0x18`, **stride 8**, key = dword0 | **Confirmed** |
| No direct FUN_* callees (indirect vtbl only) | **Confirmed** |
| 35 callers / 86 xrefs; material/FX bind traffic | **Confirmed** |
| Reject scaffold `Named_CalleeOf_*` alias; structural `_Inferred` name | **Appropriate** |
| Do **not** return index in EAX; do **not** strcmp dense table names | **Confirmed** as port hygiene |
| Product/PDB English open; table dword1 unused here; no runtime/diff | **Fair residual** |
| Dual A **accept** + B **accept** | **Appropriate** for sealed ABI/CF |

### `0x0073e1e0` (`aa_0073e1e0` / `EffEffect_CreateAndLoad_Inferred`)

| Claim | Verdict |
|---|---|
| Body `0073e1e0`–`0073e257` exclusive, 119 B | **Confirmed** |
| Live decompile ≡ raw CF (statement order); bytes win on callee ECX | **Confirmed** |
| **stdcall** 3 stack args `(manager*, pathOrToken, int* outStatus)`; **`ret 0xc`** | **Confirmed** |
| Returns effect* or null; status only via out-param | **Confirmed** |
| Freelist `DAT_00d21970` / `FUN_00457040`; block **0x30** | **Confirmed** |
| Init vtbl `PTR_FUN_00a9f9c4`; zero fields; shorts `0xFFFF` at `+0x1c/+0x1e` | **Confirmed** |
| Load `FUN_007533e0(ECX=path, obj, flag=0)`; `*outStatus = status` | **Confirmed** |
| Fail (`status < 0`): if obj, `vtbl[0](1)` (`FUN_00445020`); return null | **Confirmed** |
| Success: call `FUN_0073d830(ECX=manager, obj)`; return obj | **Confirmed** (call site) |
| Callers: `FUN_009701d0` @ `009701e7` (`DAT_00d1f61c`); `FUN_0072a660` @ `0072a92a` | **Confirmed** |
| Distinct from slot-bind wrapper `FUN_009701d0` (AddRef + swap) | **Confirmed** |
| Decompiler incomplete on path/manager ECX; dual correctly privileges bytes | **Confirmed** |
| Product English open; unowned load/register duals open; null-freelist edge open | **Fair residual** |
| Dual A **accept** + B **accept** | **Appropriate** for owned CF/ABI |

---

## Soft overclaim (unowned callee — not dual CF failure)

### `FUN_0073d830` is not a general “manager list insert”

Dual prose (report AutoCore impact / shared context / A–B surviving contracts) labels success-path `FUN_0073d830` as **manager register / list register**.

Independent decompile + body bytes of `0x0073d830`:

```text
// thiscall ECX=manager; stack effect*; ret 4
if (!effect || !effect[+8]) return;
begin = manager[+4]; end = manager[+8];
if (begin == end) return;                    // empty → no-op
// walk entries stride 0x14; key at +0 == effect.inner
// if NOT found → ret 4 (no insert)
// if found → FUN_004406e0 on (entry+4) vector, appending effect*
```

So on success of create/load, the owned unit **does** call `FUN_0073d830(manager, obj)`, but that callee:

1. No-ops if the manager list is empty or has no entry keyed by the new effect’s inner.  
2. When a match exists, appends the effect* into a **sub-vector** at the matched entry (`FUN_004406e0`), not a free-form push of a new top-level slot.

**Impact:** Owned VA control flow and ABI remain sealed. The English “register” for the **unowned** callee is **over-strong**. Safer port note: *“success-path manager touch / attach-if-inner-already-tracked (`FUN_0073d830`); do not invent a blind push_back of every new effect.”* Dual already marks `FUN_0073d830` unowned — residual naming gap only.

Severity: **low** (docs/port commentary; not a false sealed claim about bytes of `0x0073e1e0` itself).

---

## Clean reconstruction nits (non-blocking)

1. **`EffEffect_FindParamIndexByName_Inferred.cpp`** types iface method as `__thiscall`. Retail call site leaves `ECX = vtbl` and pushes `(iface, 0, name)` — stack-this / stdcall-like, not MSVC thiscall. Semantic port of the finder is fine; bit-exact call-site rewrite against retail iface would need stack-this. Dual sealed text already uses `(iface, 0, name)` without claiming thiscall on the method.  
2. **`EffEffect_CreateAndLoad_Inferred.cpp`** correctly documents freelist EDI / path+manager ECX and matches sealed CF. Freelist size 0x30 comment matches `FUN_00457040` chain step.

---

## Residual gaps (honest; duals already flag most)

1. Product/PDB English for effect shell, param iface method, manager class.  
2. Second dword of param table entries (stride-8 payload) unused by finder.  
3. Full status domain and side effects of unowned `FUN_007533e0`.  
4. Full product role of unowned `FUN_0073d830` (attach-if-tracked vs true register) — dual overclaim soft, still open.  
5. Null freelist + successful load theoretical edge (would path into load with null obj).  
6. Name vs interned-token domain at high-traffic call sites.  
7. Runtime / bit-exact / differential (terminal coverage false; no Launcher).  
8. Ghidra signatures still `undefined FUN_*(void)` while decompile+bytes recover real ABI — duals correctly privilege decompile/bytes (not dual failure).

---

## Dual quality verdict (not bare LGTM)

### `aa_00752370` — **PASS** (`accept` stands)

A/B roles are clean (fidelity vs attack table). Independent re-verify seals:

- thiscall + `ret 8`  
- always-write −1/index  
- handle→stride-8 scan (not strcmp / not EAX index)  
- body size, caller volume  

No CF, ABI, or table-layout contradiction found. Artifact chain (raw + W38-Q append, A/B, clean named) coheres. Residual gaps are product English / unowned iface only.

### `aa_0073e1e0` — **PASS** (`accept` stands; soft unowned-callee naming gap)

Strengths:

- stdcall + `ret 0xc` sealed both paths.  
- Freelist / vtbl / 0xFFFF init / load / fail-dtor / success call sealed.  
- Bytes correctly override decompiler on path ECX and manager ECX.  
- Distinguished from `EffEffectSlot_BindByPath` consumer.  
- Two callers re-confirmed at exact sites.  

Defect-class note:

- Shared-context English **“manager list register”** for `FUN_0073d830` is **over-strong** relative to that unowned callee’s CF (attach-if-inner-tracked). Does **not** falsify owned unit’s sealed call site or return contract. No dual file rewrite by this verifier.

### Pair / process quality

| Dimension | Assessment |
|---|---|
| Dual A+B present for both VAs | Yes |
| Co-owned create/load + param-index pairing | Sound (loader produces shells; finder indexes after load) |
| Port hygiene (finder vs set-param peer; factory vs slot bind) | Sound |
| Bytes-over-decompiler discipline | Sound |
| Terminal coverage honesty | Sound (`false`) |
| OWN-ONLY hygiene / no ledger edits claimed | Outside this verifier’s rewrite scope |
| Spot-check vs Ghidra live | Both units seal; one soft unowned-name overclaim |

---

## Summary

| VA | Dual quality | Verdict retention | Action |
|----|--------------|-------------------|--------|
| `0x00752370` | **PASS** | keep **accept** | none required |
| `0x0073e1e0` | **PASS** | keep **accept**; optional prose soften on `FUN_0073d830` “register” | owner may clarify unowned callee as attach-if-tracked |

**ADV artifact written:**

- `docs/reconstruction/reviews/ADV_wave38_spotcheck_00752370_0073e1e0.md` (this file)
